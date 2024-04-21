cmake_minimum_required(VERSION 3.28)

project(MatrixLib VERSION 0.1.0 DESCRIPTION "A simple library for matrix opperations")

# set directory variables 
set(SOURCE_DIR "src/")
set(TEST_DIR "test/")

# include vcpkg
include(${VCPKG_CMAKE})

# find and include Google Test
find_package(GTest)
include(GoogleTest)

# add the library
add_library(matrixlib ${SOURCE_DIR}matrix.cpp ${SOURCE_DIR}matrix.h)

# THIS IS VERY TEMPORARY
add_executable(matrix ${SOURCE_DIR}main.cpp ${SOURCE_DIR}matrix.h ${SOURCE_DIR}matrix.cpp)

# add the test exectuable
#add_executable(matrix_test ${TEST_DIR}matrix_test.cpp ${CMAKE_SOURCE_DIR}matrix.h ${CMAKE_SOURCE_DIR}matrix.cpp)
#target_link_libraries(matrix_test PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)