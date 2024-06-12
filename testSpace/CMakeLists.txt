project(testProject)


# add_compile_options(-fsanitize=address)
# add_link_options(-fsanitize=address)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 1)

add_executable(${PORJECT_NAME}_target main.cpp hutils.h )
