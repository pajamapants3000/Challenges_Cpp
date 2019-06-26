cmake_minimum_required(VERSION 2.8)

project(Challenges_Cpp)

link_directories(${CMAKE_CURRENT_BINARY_DIR}/Solutions)

add_executable(${PROJECT_NAME} "main.cpp")
add_executable(${PROJECT_NAME}_TEST "test.cpp")
add_subdirectory(Solutions)

target_include_directories(${PROJECT_NAME} PRIVATE Solutions)
target_include_directories(${PROJECT_NAME}_TEST PRIVATE Solutions)

target_link_libraries(${PROJECT_NAME} PUBLIC vowelsquare)
target_link_libraries(${PROJECT_NAME}_TEST PUBLIC vowelsquare)
