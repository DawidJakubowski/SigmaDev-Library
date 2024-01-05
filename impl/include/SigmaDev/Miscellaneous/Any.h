/**
 * \file include/SigmaDev/Miscellaneous/Any.h
 * \brief Any.h has the definition of C_Any
 * 
 * SigmaDev Library, by Dawid Jakubowski
 * Available under the MIT License
*/


#ifndef SIGMADEV_ANY_H
#define SIGMADEV_ANY_H

#include <SigmaDev/Miscellaneous/Impl.h>

namespace sigmadev {
    /////////////////////////////
    class I_Any {
    public:
        virtual std::type_index TypeIndexOfValue() const = 0;
        virtual bool operator<(const I_Any& b) const = 0;
        virtual bool operator<=(const I_Any& b) const = 0;
        virtual bool operator>(const I_Any& b) const = 0;
        virtual bool operator>=(const I_Any& b) const = 0;
        virtual bool operator==(const I_Any& b) const = 0;
        virtual bool operator!=(const I_Any& b) const = 0;
    protected:

    };
    class C_Any : public I_Any {
    public:
        C_Any();
        template <typename VALUE>
        C_Any(const VALUE& value) : any_value(new impl::_C_AnyValue<VALUE>(value)) {}
        template <typename VALUE>
        C_Any(VALUE&& value) : any_value(new impl::_C_AnyValue<VALUE>(std::move(value))) {}
        virtual ~C_Any() = default;

        template <typename VALUE>
        inline void Set(const VALUE& value) {
            if (!any_value.operator bool()) {
                any_value = std::shared_ptr<impl::_I_AnyValue>(new impl::_C_AnyValue<VALUE>(value));
            } else {
                any_value = std::shared_ptr<impl::_I_AnyValue>(new impl::_C_AnyValue<VALUE>(value));
            }
        }
        template <typename VALUE>
        inline void Move(VALUE&& value) {
            if (!any_value.operator bool()) {
                any_value = std::shared_ptr<impl::_I_AnyValue>(new impl::_C_AnyValue<VALUE>(std::move(value)));
            } else {
                any_value = std::shared_ptr<impl::_I_AnyValue>(new impl::_C_AnyValue<VALUE>(std::move(value)));
            }
        }
        template <typename VALUE>
        inline const VALUE& Cast() const {
            if (any_value) {
                const impl::_C_AnyValue<VALUE>* c_any_value = dynamic_cast<const impl::_C_AnyValue<VALUE>*>(any_value.get());
                if (c_any_value) [
                    return c_any_value->GetValue();
                ] else {
                    //TODO: Throw Exception
                }
            } else {
                //TODO: Throw Exception
            }
        }
        template <typename VALUE>
        inline VALUE& Cast() {
            if (any_value) {
                impl::_C_AnyValue<VALUE>* c_any_value = dynamic_cast<impl::_C_AnyValue<VALUE>*>(any_value.get());
                if (c_any_value) {
                    return c_any_value->GetValue();
                } else {
                    //TODO: Throw Exception
                }
            } else {
                //TODO: Throw Exception
            }
        }
        bool operator<(const I_Any& b) const override {
            //TODO
        }
        bool operator<=(const I_Any& b) const override {
            //TODO
        }
        bool operator>(const I_Any& b) const override {
            //TODO
        }
        bool operator>=(const I_Any& b) const override {
            //TODO
        }
        bool operator==(const I_Any& b) const override {
            //TODO
        }
        bool operator!=(const I_Any& b) const override {
            //TODO
        }
        std::type_index TypeIndexOfValue() const override {
            if (any_value) {
                return any_value->TypeIndexOfValue();
            } else {
                return std::type_index(typeid(void));
            }
        }
    protected:
        std::shared_ptr<impl::_I_AnyValue> any_value;
    };
    /////////////////////////////
}

#endif


//TODO: Comparison Operators
//TODO: Load From JSON (C_Type; C_JSON)
//TODO: Save To JSON (C_Type; C_JSON)
//TODO: Copy / Move / Allocate / Release Rules (C_Copy, C_Move, C_Allocate, C_Release)
//TEST_IT