cmake_minimum_required(VERSION 3.15)
project(task1)

set(CMAKE_CXX_STANDARD 14)
set(LIB_SOURCE_FILES
        MyTask.cpp)

add_executable(task1 main.cpp)

add_library(mylib STATIC ${LIB_SOURCE_FILES})
target_link_libraries(task1 mylib)


download_project(PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        ${UPDATE_DISCONNECTED_IF_AVAILABLE}
        )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# When using CMake 2.8.11 or later, header path dependencies
# are automatically added to the gtest and gmock targets.
# For earlier CMake versions, we have to explicitly add the
# required directories to the header search path ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include")
endif()

# Now simply link your own targets against gtest, gmock,
# etc. as appropriate
add_executable(test test_gtest.cpp)
target_link_libraries(test  test_gtest.cpp)
#add_test(NAME example_test COMMAND example)