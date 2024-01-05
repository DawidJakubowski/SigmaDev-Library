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
#include <SigmaDev/Miscellaneous/Impl.h>

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
class I_IDS {
public:
    virtual std::size_t Count() const = 0;
protected:

};
/////////////////////////////
class C_IDS : public I_IDS {
public:
    typedef std::map<unsigned long long, C_ID> _IDS;

    C_IDS() = default;
    virtual ~C_IDS() = default;

    std::size_t Count() const override {
        return ids.size();
    }

    inline const _IDS& GetIDS() const {
        return ids;
    }
    inline _IDS& GetIDS() {
        return ids;
    }
protected:
    _IDS ids;
};
/////////////////////////////

#endif


//TODO: Conversion from one type to another (C_Type)
//TODO: Comparison of one id to another (C_Compare)