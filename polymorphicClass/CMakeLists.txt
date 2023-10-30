cmake_minimum_required(VERSION 3.5)

project(polymorphicClass VERSION 1.0)

set(source_files main.cpp)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(${PROJECT_NAME}_target ${source_files})
