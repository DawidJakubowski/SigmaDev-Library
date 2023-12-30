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
        class _I_AnyValue {
        public:
            virtual std::type_index TypeIndexOfValue() const = 0;
        protected:

        };
        template <typename VALUE>
        class _C_AnyValue : public _I_AnyValue {
        public:
            _C_AnyValue() {}
            _C_AnyValue(VALUE&& value) : value(std::move(value)) {}
            _C_AnyValue(const VALUE& value) : value(value) {}   
            virtual ~_C_AnyValue() = default;

            std::type_index TypeIndexOfValue() const override {
                return std::type_index(typeid(VALUE));
            }
            inline const VALUE& GetValue() const {
                return value;
            }
            inline VALUE& GetValue() {
                return value;
            }
            inline void SetValue(const VALUE& value) {
                this->value = value;
            }
            inline void MoveValue(VALUE&& value) {
                this->value = std::move(value);
            }
        protected:
            VALUE value;
        };
        /////////////////////////////
    }
}

#endif