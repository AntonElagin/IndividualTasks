cmake_minimum_required(VERSION 3.15)
project(IndividualTask2 C)
set(CMAKE_C_STANDARD 11)


add_executable(IndividualTask2 main.c naive_algorithm.h parallel_algorithm.h
        naive_algorithm.c parallel_algorithm.c)

# Cтатическая библиотека
add_library(naive_algorithm_lib STATIC naive_algorithm.c)
target_include_directories(naive_algorithm_lib PRIVATE ${PROJECT_SOURCE_DIR}/)



#Динамическая библиотека
add_library(parallel_algorithm_lib SHARED parallel_algorithm.h parallel_algorithm.c)
add_library(parallel_algorithm_lib::lib_1 ALIAS parallel_algorithm_lib)
target_include_directories(parallel_algorithm_lib PUBLIC ${PROJECT_SOURCE_DIR}/ )


add_executable(naive_lib main.c)
target_link_libraries(naive_lib PRIVATE naive_algorithm_lib)
target_link_libraries(naive_lib PRIVATE parallel_algorithm_lib::lib_1)

