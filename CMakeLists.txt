cmake_minimum_required(VERSION 3.15)
project(lab1Flex)

include_directories(src)
add_subdirectory(src)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab1Flex main.cpp)

target_link_libraries(lab1Flex src)