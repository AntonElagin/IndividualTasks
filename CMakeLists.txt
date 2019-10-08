cmake_minimum_required(VERSION 3.7)
project(task1)

set(CMAKE_CXX_STANDARD 14)
set(LIB_SOURCE_FILES
        MyTask.cpp)

add_executable(task1 main.cpp)

add_library(mylib STATIC ${LIB_SOURCE_FILES})
target_link_libraries(task1 mylib)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests test_gtest.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

