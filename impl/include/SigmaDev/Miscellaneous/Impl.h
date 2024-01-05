/**
 * \file include/SigmaDev/Miscellaneous/Impl.h
 * \brief Impl.h corresponds to required elements for Miscellaneous elements, shared across Miscellaneous Module only. 
 *        It contains for the most part elements required for the most basic basic operations across the Miscellaneous Module.
 * 
 *        Implementation Class Shouldn't Inherit from the C_Class for optimalization purposes.
 *        Many of the implementation classes are proxies of the non-implementation classes.
 * 
 * SigmaDev Library, by Dawid Jakubowski
 * Available under the MIT License
*/

#ifndef SIGMADEV_IMPL_H
#define SIGMADEV_IMPL_H

#include <memory>
#include <string>
#include <typeindex>

namespace sigmadev {
    /////////////////////////////
    // Forward Declarations
    class C_Class;
    /////////////////////////////
    namespace impl {
        class _I_ClassImpl {
        public:
            _I_ClassImpl() = default;
            virtual ~_I_ClassImpl() = default;
        protected:

        };
        class _C_ClassImpl : public _I_ClassImpl {
        public:
            _C_ClassImpl(C_Class& base);

            inline void SetTypeIndexOfClass(const std::type_index typeindex_of_class) {
                this->typeindex_of_class = typeindex_of_class;
            }
        protected:
            std::type_index typeindex_of_class;
            C_Class& base;
        };
        /////////////////////////////
        class _I_IDKey {
        public:
            _I_IDKey() = default;
            virtual ~_I_IDKey() = default;
        protected:

        };
        template <typename KEY>
        class _C_IDKey : public _I_IDKey {
        public:
            _C_IDKey() = default;
            _C_IDKey(const KEY& key) : key(key) {}
            _C_IDKey(KEY&& key): key(std::move(key)) {}
            virtual ~_C_IDKey() {}

            inline const KEY& GetKey() const {
                return key;
            }
            inline KEY& GetKey() {
                return key;
            }
            inline void SetKey(const KEY& key) {
                this->key = key;
            }
            inline void MoveKey(KEY&& key) {
                this->key = std::move(key);
            }
        protected:
            KEY key;
        };
        /////////////////////////////
        class _I_AnyValue {
        public:
            virtual std::type_index TypeIndexOfValue() const = 0;
        protected:

        };     
        template <typename VALUE>
        class _C_AnyValue : public _I_AnyValue {
        public:
            _C_AnyValue() {}
            _C_AnyValue(const VALUE& value) : value(value) {}
            _C_AnyValue(VALUE&& value) : value(std::move(value)) {}
            virtual ~_C_AnyValue() {}

            std::type_index TypeIndexOfValue() const override {
                return std::type_index(typeid(VALUE));
            }
            inline void SetValue(const VALUE& value) {
                this->value = value;
            }
            inline void MoveValue(VALUE&& value) {
                this->value = std::move(value);
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
        /////////////////////////////
        class _I_TypeInfo {
        public:
            virtual std::type_index TypeIndexOfType() const = 0;
        protected:

        };
        template <typename TYPE>
        class _C_TypeInfo : public _I_TypeInfo {
        public:
            std::type_index TypeIndexOfType() const override {
                return std::type_index(typeid(TYPE));
            }
        };
        /////////////////////////////
    }
    /////////////////////////////
    class I_TypeInfo {
    public:
        I_TypeInfo() = default;
        virtual ~I_TypeInfo() = default;

        virtual std::type_index TypeIndexOfType() const = 0;
    protected:

    };
    /////////////////////////////
    class C_TypeInfo : public I_TypeInfo {
    public:
        template <typename TYPE>
        C_TypeInfo() : type_info_impl(new impl::_C_TypeInfo<TYPE>()) {}

        std::type_index TypeIndexOfType() const override {
            return type_info_impl->TypeIndexOfType();
        }
    protected:
        std::shared_ptr<impl::_I_TypeInfo> type_info_impl;
    };      
    /////////////////////////////
    class I_TypeInfos {
    public:
    
    protected:

    };
    /////////////////////////////
    class C_TypeInfos : public I_TypeInfos {
    public:

    protected:  

    };
    /////////////////////////////  
}

#endif