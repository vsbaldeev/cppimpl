cmake_minimum_required(VERSION 3.10)
project(cppimpl)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
add_executable(cppimpl examples/main.cpp src/Pimpl.h examples/Integer.h examples/Integer.cpp)