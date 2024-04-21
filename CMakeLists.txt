cmake_minimum_required(VERSION 3.10)

# set the project name
project(time-converter)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Include directories
include_directories(include)

# add the executable
add_executable(
    time-converter
    src/industrial_time.cpp
    src/main.cpp
)

# Test target
add_executable(runTests 
    src/industrial_time.cpp 
    tests/test_industrial_time.cpp
)
target_link_libraries(runTests ${GTEST_BOTH_LIBRARIES} pthread)

# Add test
add_test(NAME test_time_converter COMMAND runTests)