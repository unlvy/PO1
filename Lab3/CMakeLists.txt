cmake_minimum_required(VERSION 3.1)

project (lab3)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS " -Wall")

file(GLOB SOURCES *.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

add_custom_target(run ./main)
add_custom_target(check valgrind ./main)
