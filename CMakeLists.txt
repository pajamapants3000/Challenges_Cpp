cmake_minimum_required(VERSION 2.8)

project(Challenges_Cpp)

link_directories(${CMAKE_CURRENT_BINARY_DIR}/Solutions)

add_subdirectory(Solutions)

add_executable(${PROJECT_NAME} "main.cpp")
add_executable(${PROJECT_NAME}_TEST "test.cpp")

target_include_directories(${PROJECT_NAME} PRIVATE Solutions)
target_include_directories(${PROJECT_NAME}_TEST PRIVATE Solutions)

target_link_libraries(${PROJECT_NAME} vowelsquare)
target_link_libraries(${PROJECT_NAME}_TEST vowelsquare)
target_link_libraries(${PROJECT_NAME} palindromenumber)
target_link_libraries(${PROJECT_NAME}_TEST palindromenumber)
target_link_libraries(${PROJECT_NAME} addtwonumbers)
target_link_libraries(${PROJECT_NAME}_TEST addtwonumbers)
target_link_libraries(${PROJECT_NAME} closestenemy)
target_link_libraries(${PROJECT_NAME}_TEST closestenemy)
target_link_libraries(${PROJECT_NAME} laststoneweight)
target_link_libraries(${PROJECT_NAME}_TEST laststoneweight)
