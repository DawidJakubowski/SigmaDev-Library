/**
 * \file include/SigmaDev/Miscellaneous/Common.h
 * \brief Common corresponds to ...
 * 
 * SigmaDev Library, by Dawid Jakubowski
 * Available under the MIT License
*/

#ifndef SIGMADEV_COMMON_H
#define SIGMADEV_COMMON_H

namespace sigmadev {
    /////////////////////////////
    class I_Condition {
    public:

    protected:

    };
    /////////////////////////////
    class C_Condition : public I_Condition {
    public:

    protected:

    };
    /////////////////////////////
    class I_Signal {
    public:

    protected:

    };
    /////////////////////////////
    class C_Signal {
    public:

    protected:

    };
    /////////////////////////////
    class I_Return {
    public:
        I_Return() = default;
        virtual ~I_Return() = default;
        
        virtual bool Ok() const = 0;
    protected:

    };
    /////////////////////////////
    class C_Return {
    public:

    protected:

    };
    /////////////////////////////
}

#endif