cmake_minimum_required(VERSION 3.5)

project(polymorphicClass VERSION 1.0)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(basics_target basics.cpp)
add_executable(virtualDispatchAccessControl1_target virtualDispatchAccessControl1.cpp)
add_executable(virtualDispatchAccessControl2_target virtualDispatchAccessControl2.cpp)
add_executable(typeid_vs_dynamic_cast_target typeid_vs_dynamic_cast.cpp)

