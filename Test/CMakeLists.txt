cmake_minimum_required(VERSION 2.8)

project(TestTest)

link_directories(${CMAKE_CURRENT_BINARY_DIR}/..)

add_executable(testrun "testrun.cpp")
add_library(testclass "test.cpp")
target_link_libraries(testrun testclass boost_unit_test_framework)

