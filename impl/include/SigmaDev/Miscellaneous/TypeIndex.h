/////////////////////////////////////////////////////
///
/// SigmaDev Library 
/// Copyright © 2024 Dawid Jakubowski All Rights Reserved
/// Under MIT License
///
/////////////////////////////////////////////////////

#ifndef SIGMADEV_TYPEINDEX_H
#define SIGMADEV_TYPEINDEX_H

#include <typeindex>

template <typename TYPE>
inline std::type_index TypeIndexOf() {
    return std::type_index(typeid(TYPE));
}

#endif // SIGMADEV_TYPEINDEX_H