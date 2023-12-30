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
        I_Any() = default;
        virtual ~I_Any() = default;

        virtual std::type_index TypeIndexOfValue() const = 0;
    protected:

    };
    /////////////////////////////
    class C_Any : public I_Any {
    public:
        C_Any();
        template <typename VALUE>
        C_Any(const VALUE& value) : value(value) {}
        template <typename VALUE>
        C_Any(VALUE&& value) : value(std::move(value)) {}

        virtual ~C_Any() = default;

        template <typename VALUE>
        void SetValue(const VALUE& value) {
            this->value = std::shared_ptr<impl::_I_AnyValue>(new impl::_C_AnyValue<VALUE>(value));
        }
        template <typename VALUE>
        void MoveValue(VALUE&& value) {
            this->value = std::shared_ptr<impl::_I_AnyValue>(new impl::_C_AnyValue<VALUE>(std::move(value)));
        }

        virtual std::type_index TypeIndexOfValue() const override;
    protected:
        std::shared_ptr<impl::_I_AnyValue> value;
    };
    /////////////////////////////
}

#endif


//TODO: Comparison Operators
//TODO: Load From JSON (C_Type; C_JSON)
//TODO: Save To JSON (C_Type; C_JSON)
//TODO: Copy / Move / Allocate / Release Rules (C_Copy, C_Move, C_Allocate, C_Release)
//TEST_IT