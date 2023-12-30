/**
 * \file src/SigmaDev/Exception.cpp
 * \brief Definition of C_Exception and related
 * 
 * SigmaDev Library, by Dawid Jakubowski
 * Available under the MIT License
*/

#include <SigmaDev/Miscellaneous/Exception.h>
#include <SigmaDev/Miscellaneous/Data.h>

namespace sigmadev {
    C_Exception::C_Exception(const std::string& name, const C_Description& description, C_Data&& data) : name(name), description(description), data(std::move(data)) {

    }

    const std::string& C_Exception::ExceptionName() const {
        return name;
    }
    const std::string& C_Exception::ExceptionDescription() const {
        return description.String();
    }
}

