cmake_minimum_required(VERSION 3.5)

project(type_cast_operatorFunction VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 1)

set(source_files main.cpp)

add_executable(${PROJECT_NAME}_target ${source_files})
