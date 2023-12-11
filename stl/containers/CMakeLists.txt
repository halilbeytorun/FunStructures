cmake_minimum_required(VERSION 3.5)

project(containers VERSION 1.0)

set(CMAKE_CXX_STANDARD_REQUIRED 1)
set(CMAKE_CXX_STANDARD 20)

add_executable(vector_add_element_target vector_add_element.cpp)
add_executable(vector_iterators_target vector_iterators.cpp)
add_executable(vector_constructors_target vector_constructors.cpp)
add_executable(vector_other_functions_target vector_other_functions.cpp)
add_executable(vector_change_size_target vector_change_size.cpp)
add_executable(vector_comparison_target vector_comparison.cpp)

