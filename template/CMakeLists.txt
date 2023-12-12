cmake_minimum_required(VERSION 3.5)

project(template VERSION 1.0)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(typeTeller_target typeTeller.cpp)
add_executable(typeDeduction_target typeDeduction.cpp)
add_executable(SFINAE_target SFINAE.cpp)
add_executable(template_n_range_target template_n_range.cpp)
add_executable(perfectForwarding_target perfectForwarding.cpp)
add_executable(explicitSpecialization_target explicitSpecialization.cpp)
add_executable(partialSpecialization_target partialSpecialization.cpp)
add_executable(aliasTemplate_target aliasTemplate.cpp)
add_executable(variableTemplate_target variableTemplate.cpp)
add_executable(variadicTemplates_target variadicTemplates.cpp)
add_executable(logger_target logger.cpp)


