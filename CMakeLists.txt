cmake_minimum_required  (VERSION 3.1)
project                 (matrix)
set (matrix_VERSION_MAJOR 0)
set (matrix_VERSION_MINOR 1)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set (CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS} -O0 -ggdb3")
set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3")


set (
    Matrix_SOURCES
    ${PROJECT_SOURCE_DIR}/main.cpp
)

add_executable (
    matrix
    ${Matrix_SOURCES}
)
