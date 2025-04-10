cmake_minimum_required(VERSION 3.11.0)

# Set the project name and version
project(matrix VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the compiler
#set(CMAKE_CXX_COMPILER /usr/bin/g++)

# Define source and include paths
set(PRJ_SRC_PATH src/)
set(PRJ_INC_PATH inc/)
set(PRJ_TST_PATH test/)

# Add coverage flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# Disable unnecessary options for GoogleTest
set(BUILD_GMOCK OFF)
set(INSTALL_GTEST OFF)
FetchContent_MakeAvailable(googletest)

# Find Boost
find_package(Boost REQUIRED COMPONENTS iostreams)

# Include Boost headers
include_directories(${Boost_INCLUDE_DIRS})


# Add the library
add_library(matrix_lib 
  ${PRJ_SRC_PATH}Matrix.cpp
  ${PRJ_SRC_PATH}GeometricObject.cpp 
  ${PRJ_SRC_PATH}Circle.cpp 
  ${PRJ_SRC_PATH}Rectangle.cpp )
target_include_directories(matrix_lib PUBLIC ${PRJ_INC_PATH})

# Enable code coverage
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(matrix_lib PRIVATE --coverage)
    target_link_options(matrix_lib PRIVATE --coverage)
endif()

# Add the executable
add_executable(${PROJECT_NAME} ${PRJ_SRC_PATH}main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE matrix_lib)
# Link Boost libraries
target_link_libraries(matrix PRIVATE ${Boost_LIBRARIES})

# Link GoogleTest for unit testing
enable_testing()
add_executable(${PROJECT_NAME}_tests ${PRJ_TST_PATH}testMatrix.cpp)
target_link_libraries(${PROJECT_NAME}_tests PRIVATE matrix_lib gtest gtest_main)
target_include_directories(${PROJECT_NAME}_tests PRIVATE ${PRJ_INC_PATH})

# Enable code coverage
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(${PROJECT_NAME}_tests PRIVATE --coverage)
    target_link_options(${PROJECT_NAME}_tests PRIVATE --coverage)
endif()

# Add tests
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_tests)