/**
 * \file include/SigmaDev/Miscellaneous/Class.h
 * \brief Class.h has the definition of the C_Class
 *        I_ClassSettings and C_ClassSettings shouldn't be inheriting from C_Class.  
 * 
 * SigmaDev Library, by Dawid Jakubowski
 * Available under the MIT License
*/

#ifndef SIGMADEV_CLASS_H
#define SIGMADEV_CLASS_H

#include <typeindex>
#include <string>
#include <SigmaDev/Miscellaneous/Impl.h>

namespace sigmadev {
    /////////////////////////////
    class I_ClassSettings {
    public:
        I_ClassSettings() = default;
        virtual ~I_ClassSettings() = default;
    protected:

    };
    /////////////////////////////
    class C_ClassSettings : public I_ClassSettings {
    public:
        C_ClassSettings() = default;
        virtual ~C_ClassSettings() = default;
    
        inline void SetConcreteClassName(const std::string& concrete_class_name) {
            this->concrete_class_name = concrete_class_name;
        }
        std::type_index SetConcreteClassTypeIndex(const std::type_index& concrete_type_index) {
            this->concrete_type_index = concrete_type_index;
        }
    protected:
        
        std::string concrete_class_name;
        std::type_index concrete_type_index;
    };
    /////////////////////////////
    class I_Class {
    public:
        I_Class() = default;
        virtual ~I_Class() = default;

        virtual std::type_index TypeIndexOfConcreteClass() const = 0;
        virtual std::string TrueNameOfConcreteClass() const = 0;
    protected:  

    };
    /////////////////////////////
    /**
     * Important: All Classes should inherit from the C_Class
     *            The only exceptions are: I_ClassSettings and C_ClassSettings,
     *            and Implementation (inside sigmadev::impl:: namespaces) classes
    */
    class C_Class : public I_Class {
    public:
        C_Class(const C_ClassSettings& class_settings);
        C_Class();

        virtual std::type_index TypeIndexOfConcreteClass() const override;
        virtual std::string TrueNameOfConcreteClass() const override;
    protected:
        
    };
    /////////////////////////////
}

#endif