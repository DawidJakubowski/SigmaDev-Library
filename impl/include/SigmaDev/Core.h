/**
 * \file include/SigmaDev/Core.h
 * \brief Core Module Include Header
 * 
 * SigmaDev Library, by Dawid Jakubowski
 * Available under the MIT License
*/

#ifndef SIGMADEV_CORE_MAIN_H
#define SIGMADEV_CORE_MAIN_H

#include <SigmaDev/Miscellaneous/Type.h>

/////////////////////////////
// Forward Declarations
class C_Types;
/////////////////////////////

class I_Core {
public:

protected:

};
class C_Core : public I_Core {
public:

protected:
    std::shared_ptr<C_Types> core_types;
};

#endif