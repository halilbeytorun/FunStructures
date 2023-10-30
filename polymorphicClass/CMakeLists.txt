cmake_minimum_required(VERSION 3.5)

project(polymorphicClass VERSION 1.0)

set(source_files basics.cpp)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(${PROJECT_NAME}_target ${source_files})
add_executable(virtualDispatchAccessControl1_target virtualDispatchAccessControl1.cpp)
add_executable(virtualDispatchAccessControl2_target virtualDispatchAccessControl2.cpp)

