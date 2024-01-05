/**
 * \file include/SigmaDev/Core/Core.h
 * \brief 
 * 
 * SigmaDev Library, by Dawid Jakubowski
 * Available under the MIT License
*/

#ifndef SIGMADEV_CORE_H
#define SIGMADEV_CORE_H

#include <memory>
#include <string>
#include <SigmaDev/Miscellaneous/Common.h>
#include <SigmaDev/Miscellaneous/Class.h>
#include <SigmaDev/Miscellaneous/Type.h>
#include <SigmaDev/Miscellaneous/References.h>

/////////////////////////////
class I_CoreSettings {
public:
    I_CoreSettings() = default;
    virtual ~I_CoreSettings() = default;
protected:
};
/////////////////////////////
class C_CoreSettings : public I_CoreSettings {
public:

protected:  

};
/////////////////////////////
class I_Core {
public:
    I_Core() = default;
    virtual ~I_Core() = default;


protected:

};
/////////////////////////////
class C_Core : public I_Core {
public:
    C_Core() = delete;
    C_Core(
        const C_CoreSettings& core_settings,
        C_References& references
    );
    virtual ~C_Core() = default;
protected:

};
/////////////////////////////

#endif