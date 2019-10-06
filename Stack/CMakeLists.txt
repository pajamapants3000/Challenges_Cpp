cmake_minimum_required(VERSION 2.8)

project(Stack)

link_directories(${CMAKE_CURRENT_BINARY_DIR}/..)

add_executable(${PROJECT_NAME}_TEST "stacktest.cpp"
    "standardstacktest.cpp"
    "multistacktest.cpp"
    "threeinonestacktest.cpp"
)
add_library(stacks "stacks.cpp")

target_link_libraries(${PROJECT_NAME}_TEST
    boost_unit_test_framework
    stacks
)
