/**
 * \file include/SigmaDev/Miscellaneous/Exception.h
 * \brief Exception.h has the definition of the Exception class
 * 
 * SigmaDev Library, by Dawid Jakubowski
 * Available under the MIT License
*/

#ifndef SIGMADEV_EXCEPTION_H
#define SIGMADEV_EXCEPTION_H

#include <memory>
#include <string>

namespace sigmadev {
    /////////////////////////////
    // Forward Declarations
    class C_Description;
    class C_Data;
    /////////////////////////////
    class I_Exception {
    public:
        I_Exception() = default;
        virtual ~I_Exception() = default;

        virtual const std::string& ExceptionName() const = 0;
        virtual const std::string& ExceptionDescription() const = 0;
    protected:

    };
    /////////////////////////////
    /**
     * \brief Base class from which each concrete exception should inherit from
    */
    class C_Exception : public I_Exception {
    public:
        C_Exception() = delete;
        C_Exception(const std::string& name, const C_Description& description, C_Data&& data);
        virtual ~C_Exception() = default;

        virtual const std::string& ExceptionName() const override;
        virtual const std::string& ExceptionDescription() const override;
    protected:
        std::string name;
        std::shared_ptr<C_Description> description,
        std::shared_ptr<C_Data> data;
    };
    /////////////////////////////
    namespace exc {

    }
}


#endif