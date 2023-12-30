/**
 * \file include/SigmaDev/Data.h
 * \brief Data 
 * 
 * SigmaDev Library, by Dawid Jakubowski
 * Available under the MIT License
*/

#ifndef SIGMADEV_DATA_H
#define SIGMADEV_DATA_H

#include <memory>
#include <map>
#include <string>
#include <SigmaDev/Miscellaneous/Any.h>

namespace sigmadev {
    /////////////////////////////
    class I_Variable {
    public:
        I_Variable() = default;
        virtual ~I_Variable() = default;

        virtual std::string VariableName() const = 0;
        virtual C_Any AsAny() const = 0;
    protected:

    };
    /////////////////////////////
    class C_Variable : public I_Variable {
    public:
        virtual std::string VariableName() const override;
        virtual C_Any AsAny() const override;
        
    protected:
        
    };
    /////////////////////////////
    class I_Data {
    public:
        I_Data() = default;
        virtual ~I_Data() = default;
    protected:  

    };
    /////////////////////////////
    class C_Data : public I_Data {
    public:
        typedef std::map<std::string, std::shared_ptr<C_Variable>> _Variables;

        C_Data() = default;
        virtual ~C_Data() = default;
    protected:
        _Variables variables;
    };
    /////////////////////////////
}

#endif