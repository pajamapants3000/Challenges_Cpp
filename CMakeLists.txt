cmake_minimum_required(VERSION 2.8)

project(Challenges_Cpp)

link_directories(${CMAKE_CURRENT_BINARY_DIR}/Solutions)

add_subdirectory(Solutions)

add_executable(${PROJECT_NAME} "main.cpp")
add_executable(${PROJECT_NAME}_TEST "maintest.cpp")
add_executable(${PROJECT_NAME}_SORTTEST "sorttest.cpp")

add_library(solver "solver.cpp")

target_include_directories(${PROJECT_NAME} PRIVATE Solutions)
target_include_directories(${PROJECT_NAME}_TEST PRIVATE Solutions)

target_link_libraries(${PROJECT_NAME} solver)
target_link_libraries(${PROJECT_NAME}_TEST solver)
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
target_link_libraries(${PROJECT_NAME} stringsort)
target_link_libraries(${PROJECT_NAME}_TEST stringsort)
target_link_libraries(${PROJECT_NAME} isunique)
target_link_libraries(${PROJECT_NAME}_TEST isunique)
target_link_libraries(${PROJECT_NAME} arepermutations)
target_link_libraries(${PROJECT_NAME}_TEST arepermutations)
target_link_libraries(${PROJECT_NAME} urlify)
target_link_libraries(${PROJECT_NAME}_TEST urlify)
target_link_libraries(${PROJECT_NAME} palindromepermutation)
target_link_libraries(${PROJECT_NAME}_TEST palindromepermutation)
target_link_libraries(${PROJECT_NAME} oneaway)
target_link_libraries(${PROJECT_NAME}_TEST oneaway)

