/////////////////////////////////////////////////////
///
/// SigmaDev Library 
/// Copyright © 2024 Dawid Jakubowski All Rights Reserved
/// Under MIT License
///
/////////////////////////////////////////////////////

#ifndef SIGMADEV_ANY_H
#define SIGMADEV_ANY_H

#include <memory>
#include <typeindex>

namespace impl {
    class _SD_I_AnyValue {
    public:
        _SD_I_AnyValue() = default;
        virtual ~_SD_I_AnyValue() = default;

        virtual std::type_index TypeIndexOfValue() const = 0;
        
    protected:

    };
    template <typename VALUE>
    class _SD_AnyValue : public _SD_I_AnyValue {
    public:
        _SD_AnyValue() {}
        _SD_AnyValue(const VALUE& value) : value(value) {}
        _SD_AnyValue(VALUE&& value) : value(std::move(value)){}
        virtual ~_SD_AnyValue() {} 
    
        std::type_index TypeIndexOfValue() const override {
            return std::type_index(typeid(VALUE));
        }
        inline void MoveValue(VALUE&& value) {
            this->value = std::move(value);
        }
        inline void SetValue(const VALUE& value) {
            this->value = value;
        }
        inline const VALUE& GetValue() const {
            return value;
        }
        inline VALUE& GetValue() {
            return value;
        }
    protected:
        VALUE value;
    };
}
/////////////////////////////////////////////////////
class SD_I_Any {
public:
    SD_I_Any() = default;
    virtual ~SD_I_Any() = default;

    virtual std::type_index TypeIndexOfValue() const = 0;
    virtual bool IsInitialized() const = 0;
protected:

};
/////////////////////////////////////////////////////
class SD_Any : public SD_I_Any {
public:
    SD_Any();
    template <typename VALUE>
    SD_Any(const VALUE& value) : impl(new impl::_SD_AnyValue<VALUE>(value)) {}
    template <typename VALUE>
    SD_Any(VALUE&& value) : impl(new impl::_SD_AnyValue<VALUE>(std::move(value))) {}
    virtual ~SD_Any() = default;

    virtual std::type_index TypeIndexOfValue() const override;
    virtual bool IsInitialized() const override;
    
    template <typename VALUE>
    const VALUE& Cast() const {
        if (impl) {
            const impl::_SD_AnyValue<VALUE>* c_impl = dynamic_cast<const impl::_SD_AnyValue<VALUE>*>(impl.get());
            if (c_impl) {
                return c_impl->GetValue();
            }
        }
        //TODO: Throw Exception
    }
    template <typename VALUE>
    VALUE& Cast() {
        if (impl) {
            impl::_SD_AnyValue<VALUE>* c_impl = dynamic_cast<impl::_SD_AnyValue<VALUE>*(impl.get());
            if (c_impl) {
                return c_impl->GetValue();
            }
        }
        //TODO: Throw Exception
    }
    template <typename VALUE>
    const VALUE* CastPtr() const {
        if (impl) {
            const impl::_SD_AnyValue<VALUE>* c_impl = dynamic_cast<const impl::_SD_AnyValue<VALUE>*>(impl.get());
            if (c_impl) {
                return &c_impl->GetValue();
            }
        }
        return nullptr;
    }
    template <typename VALUE>
    VALUE* CastPtr() {
        if (impl) {
            impl::_SD_AnyValue<VALUE>* c_impl = dynamic_cast<impl::_SD_AnyValue<VALUE>*(impl.get());
            if (c_impl) {
                return &c_impl->GetValue();
            }
        }
        return nullptr;
    }
protected:
    std::unique_ptr<impl::_SD_I_AnyValue> impl;
};
/////////////////////////////////////////////////////

#endif // SIGMADEV_ANY_H