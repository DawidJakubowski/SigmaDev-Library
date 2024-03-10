
cmake_minimum_required(VERSION 3.22)
project(SigmaDevLibrary)

add_subdirectory(impl/)
include_directories(impl/include/)
include_directories(include/)

link_directories(extlib/)

add_executable(sigmadev_api ${SOURCES_API})
add_library(sigmadev ${SOURCES_LIBRARY})

target_link_libraries(sigmadev_api gtest gmock)