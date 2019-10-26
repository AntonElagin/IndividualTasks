cmake_minimum_required(VERSION 3.7)

project(IndividualTask2)

#
set(CMAKE_CXX_STANDARD 14)

# флаги
set(CMAKE_CXX_FLAGS "-O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)
SET(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
#



#Добавляем Gtest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
# Cтатическая библиотека
add_library(naive_algorithm_lib STATIC naive_algorithm.cpp)
 target_include_directories(naive_algorithm_lib PRIVATE ${PROJECT_SOURCE_DIR}/)

#Динамическая библиотека
add_library(parallel_algorithm_lib SHARED parallel_algorithm.cpp)
#add_library(parallel_algorithm_lib::lib_1 ALIAS parallel_algorithm_lib)
target_include_directories(parallel_algorithm_lib PUBLIC ${PROJECT_SOURCE_DIR}/ )

add_executable(IndividualTask2 main.cpp)
target_link_libraries(IndividualTask2 PRIVATE naive_algorithm_lib)
target_link_libraries(IndividualTask2 PRIVATE parallel_algorithm_lib)

add_executable(runTests test_gtest.cpp)
target_link_libraries(runTests PRIVATE ${GTEST_LIBRARIES} pthread)
target_link_libraries(runTests PUBLIC naive_algorithm_lib)
target_link_libraries(runTests PUBLIC parallel_algorithm_lib)




#Добавляем CTest для использования gcovr
include(CTest)
add_executable(hello test_gtest.cpp)
add_test(hello_test ${EXECUTABLE_OUTPUT_PATH}/hello)
add_definitions(-fprofile-arcs -ftest-coverage)
target_link_libraries(hello -fprofile-arcs)
target_link_libraries(hello ${GTEST_LIBRARIES} pthread)
target_link_libraries(hello naive_algorithm_lib)
target_link_libraries(hello parallel_algorithm_lib)

#add_library(libgtest STATIC ${GTEST_LIBRARIES})



