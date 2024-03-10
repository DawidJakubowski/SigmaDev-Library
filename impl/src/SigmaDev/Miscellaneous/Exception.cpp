/////////////////////////////////////////////////////
///
/// SigmaDev Library 
/// Copyright © 2024 Dawid Jakubowski All Rights Reserved
/// Under MIT License
///
/////////////////////////////////////////////////////

#include <SigmaDev/Miscellaneous/Exception.h>

const std::string& SD_Exception::ExceptionName() const {
    return exception_name;
}
const std::string& SD_Exception::ExceptionDescription() const {
    return exception_description;
}