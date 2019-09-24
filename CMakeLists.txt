cmake_minimum_required(VERSION 2.8)

project(Challenges_Cpp)

link_directories(${CMAKE_CURRENT_BINARY_DIR}/Solutions)

add_subdirectory(Solutions)

add_executable(${PROJECT_NAME} "main.cpp")
add_executable(${PROJECT_NAME}_TEST "maintest.cpp")
add_executable(${PROJECT_NAME}_SORTTEST "sorttest.cpp" "Solutions/solutionio.cpp")

add_library(solver "solver.cpp")

target_include_directories(${PROJECT_NAME} PRIVATE Solutions)
target_include_directories(${PROJECT_NAME}_TEST PRIVATE Solutions)

target_link_libraries(${PROJECT_NAME} solver)
target_link_libraries(${PROJECT_NAME}_TEST solver)
target_link_libraries(solver solutionfactory)
