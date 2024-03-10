/////////////////////////////////////////////////////
///
/// SigmaDev Library 
/// Copyright © 2024 Dawid Jakubowski All Rights Reserved
/// Under MIT License
///
/////////////////////////////////////////////////////

#ifndef SIGMADEV_EXCEPTION_H
#define SIGMADEV_EXCEPTION_H

#include <string>

/////////////////////////////////////////////////////
class SD_I_Exception {
public:
    virtual const std::string& ExceptionName() const = 0;
    virtual const std::string& ExceptionDescription() const = 0;
protected:
    
};
/////////////////////////////////////////////////////
class SD_Exception : public SD_I_Exception {
public:
    SD_Exception() = delete;
    SD_Exception(const std::string& exception_name);
    SD_Exception(const std::string& exception_name,
                 const std::string& exception_description);
    virtual ~SD_Exception() = default;

    virtual const std::string& ExceptionName() const override;
    virtual const std::string& ExceptionDescription() const override;
protected:
    std::string exception_name;
    std::string exception_description;
};
/////////////////////////////////////////////////////

#endif // SIGMADEV_EXCEPTION_H