cmake_minimum_required(VERSION 3.19)

project(chickenfarmer)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_VERBOSE_MAKEFILE TRUE)

include(GNUInstallDirs)
include(CTest)

enable_testing()
add_subdirectory("googletest")
add_subdirectory("include")
add_subdirectory("src")
add_subdirectory("test")
