cmake_minimum_required(VERSION 3.7)
project(task1)

set(CMAKE_CXX_STANDARD 14)
set(LIB_SOURCE_FILES
        my_task.cpp)

SET(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")



add_executable(task1 main.cpp)

add_library(mylib STATIC ${LIB_SOURCE_FILES})
target_link_libraries(task1 mylib)

add_executable(consoleTest test_main.cpp)
target_link_libraries(consoleTest mylib)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests
        test_gtest.cpp
        tests/mytestinput.txt
        tests/output.txt)

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(runTests mylib)


include(CTest)
add_executable(hello test_gtest.cpp)
add_test(hello_test ${EXECUTABLE_OUTPUT_PATH}/hello)
add_definitions(-fprofile-arcs -ftest-coverage)
target_link_libraries(hello -fprofile-arcs)
target_link_libraries(hello ${GTEST_LIBRARIES} pthread)
target_link_libraries(hello mylib)

#add_library(libgtest STATIC ${GTEST_LIBRARIES})

