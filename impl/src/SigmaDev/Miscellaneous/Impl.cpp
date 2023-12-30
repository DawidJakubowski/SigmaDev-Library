/**
 * \file src/SigmaDev/Miscellaneous/Impl.cpp
 * \brief Impl.cpp has the common, Miscellaneous Module implementation definitions
 * 
 * SigmaDev Library, by Dawid Jakubowski
 * Available under the MIT License
*/

#include <SigmaDev/Miscellaneous/Impl.h>
#include <SigmaDev/Miscellaneous/Class.h>

namespace sigmadev {
    namespace impl {
         _C_ClassImpl::_C_ClassImpl(C_Class& base) : base(base) {} 
    }
}