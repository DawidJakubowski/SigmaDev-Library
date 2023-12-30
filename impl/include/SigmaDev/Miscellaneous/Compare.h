/**
 * \file include/SigmaDev/Miscellaneous/Compare.h
 * \brief Compare.h has the declarations of C_Compare and C_Compares
 * 
 * SigmaDev Library, by Dawid Jakubowski
 * Available under the MIT License
*/

#ifndef SIGMADEV_COMPARES_H
#define SIGMADEV_COMPARES_H

#include <typeindex>
#include <SigmaDev/Miscellaneous/Class.h>

class I_Compare {
public:
    I_Compare() = default;
    virtual ~I_Compare() = default;
protected:

};
class C_Compare : public I_Compare {
public:

protected:

};
class C_PairCompare : public I_Compare {
public:

protected:

};
class C_TypeIndexPairCompare : public C_PairCompare {
public:

protected:

};
class I_Compares {
public:

protected:

};
class C_Compares : public I_Compares {
public:

protected:

};

#endif