cmake_minimum_required(VERSION 3.5)

project(template VERSION 1.0)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(typeTeller_target typeTeller.cpp)
add_executable(typeDeduction_target typeDeduction.cpp)

