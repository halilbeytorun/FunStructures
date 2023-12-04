cmake_minimum_required(VERSION 3.5)

project(iterators VERSION 1.0)

set(CMAKE_CXX_STANDARD_REQUIRED 1)
set(CMAKE_CXX_STANDARD 20)

add_executable(iteratorCategories_target iteratorCategories.cpp)
add_executable(algorithms_target algorithms.cpp)
add_executable(constant_iterator_target constant_iterator.cpp)
