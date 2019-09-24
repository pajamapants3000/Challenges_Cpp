cmake_minimum_required(VERSION 2.8)

project(Solutions)

link_directories(${CMAKE_CURRENT_BINARY_DIR}/..)

add_library(solution "solution.cpp" "solutionio.cpp")
add_library(solutionfactory "solutionfactory.cpp")
add_library(vowelsquare "vowelsquare.cpp")
add_library(palindromenumber "palindromenumber.cpp")
add_library(addtwonumbers "addtwonumbers.cpp")
add_library(closestenemy "closestenemy.cpp")
add_library(laststoneweight "laststoneweight.cpp")
add_library(stringsort "stringsort.cpp")
add_library(isunique "isunique.cpp")
add_library(arepermutations "arepermutations.cpp")
add_library(urlify "urlify.cpp")
add_library(palindromepermutation "palindromepermutation.cpp")
add_library(oneaway "oneaway.cpp")
add_library(compressstring "compressstring.cpp")
add_library(rotatematrix "rotatematrix.cpp")
add_library(zeromatrix "zeromatrix.cpp")
add_library(stringrotation "stringrotation.cpp")
add_library(removedups "removedups.cpp")

target_link_libraries(vowelsquare solution)
target_link_libraries(palindromenumber solution)
target_link_libraries(addtwonumbers solution)
target_link_libraries(closestenemy solution)
target_link_libraries(laststoneweight solution)
target_link_libraries(stringsort solution)
target_link_libraries(isunique solution)
target_link_libraries(arepermutations solution)
target_link_libraries(urlify solution)
target_link_libraries(palindromepermutation solution)
target_link_libraries(oneaway solution)
target_link_libraries(compressstring solution)
target_link_libraries(rotatematrix solution)
target_link_libraries(zeromatrix solution)
target_link_libraries(stringrotation solution)
target_link_libraries(removedups solution)

target_link_libraries(solutionfactory
    vowelsquare
    palindromenumber
    addtwonumbers
    closestenemy
    laststoneweight
    stringsort
    isunique
    arepermutations
    urlify
    palindromepermutation
    oneaway
    compressstring
    rotatematrix
    zeromatrix
    stringrotation
    removedups
)
