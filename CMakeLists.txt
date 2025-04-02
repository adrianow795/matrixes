cmake_minimum_required(VERSION 3.11.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PRJ_SRC_PATH src/)

project(matrix)
add_executable(${PROJECT_NAME} ${PRJ_SRC_PATH}main.cpp ${PRJ_SRC_PATH}Matrix.cpp)
target_include_directories(matrix PRIVATE inc/)
