cmake_minimum_required(VERSION 3.5)

project(exceptionHandling VERSION 1.0)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(throwOnlyTerminate throwOnlyTerminate.cpp)
add_executable(basics basics.cpp)




