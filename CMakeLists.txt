cmake_minimum_required(VERSION 3.16)
project(directory)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -O3)

#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)

foreach (EXECUTABLE main)
    add_executable(${EXECUTABLE} source/${EXECUTABLE}.cpp)
endforeach ()