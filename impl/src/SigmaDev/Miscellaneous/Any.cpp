/////////////////////////////////////////////////////
///
/// SigmaDev Library 
/// Copyright © 2024 Dawid Jakubowski All Rights Reserved
/// Under MIT License
///
/////////////////////////////////////////////////////

#include <SigmaDev/Miscellaneous/Any.h>

std::type_index SD_Any::TypeIndexOfValue() const {
    if (impl) {
        return impl->TypeIndexOfValue();
    } else {
        return std::type_index(typeid(void));
    }
}
bool SD_Any::IsInitialized() const {
    return impl.operator bool();
}