
cmake_minimum_required(VERSION 3.27)
project(SigmaDevLibrary)

add_subdirectory(impl/)
include_directories(impl/include/)

add_executable(sigmadev_api ${SOURCES_API})
add_library(sigmadev ${SOURCES_LIBRARY})