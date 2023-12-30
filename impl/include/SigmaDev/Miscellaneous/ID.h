/**
 * \file include/SigmaDev/Miscellaneous/ID.h
 * \brief C_ID is specialized class representing identifier
 * 
 * SigmaDev Library, by Dawid Jakubowski
 * Available under the MIT License
*/

#ifndef SIGMADEV_ID_H
#define SIGMADEV_ID_H

#include <SigmaDev/Miscellaneous/Class.h>

/////////////////////////////
class I_ID {
public:
    I_ID() = default;
    virtual ~I_ID() = default;
protected:

};
/////////////////////////////
class C_ID : public I_ID {
public:
    C_ID() = default;
    virtual ~C_ID() = default;
protected:

};
/////////////////////////////

#endif


//TODO: Conversion from one type to another (C_Type)
//TODO: Comparison of one id to another (C_Compare)