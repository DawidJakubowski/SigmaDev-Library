/**
 * \file include/SigmaDev/Miscellaneous/Type.h
 * \brief Type.h has the definitions for C_Type
 * 
 * SigmaDev Library, by Dawid Jakubowski
 * Available under the MIT License
*/

#ifndef SIGMADEV_TYPE_H
#define SIGMADEV_TYPE_H

#include <map>
#include <SigmaDev/Miscellaneous/ID.h>

/////////////////////////////
class I_Type {
public:
    I_Type() = default;
    virtual ~I_Type() = default;
protected:

};
/////////////////////////////
class C_Type : public I_Type {
public:
    
protected:

};
/////////////////////////////
class I_Types {
public:
    I_Types() = default;
    virtual ~I_Types() = default;
protected:

};
/////////////////////////////
class C_Types : public I_Types {
public:
    typedef std::map<C_ID, std::shared_ptr<C_Type>> _Types;

    C_Types() = default;
    virtual ~C_Types() = default;

    inline const _Types& GetTypes() const {
        return types;
    }
    inline _Types& GetTypes() {
        return types;
    }
protected:
    _Types types;
};
/////////////////////////////

#endif