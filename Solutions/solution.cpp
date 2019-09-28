#include "solution.h"

#include <string>
#include <vector>

Solution::~Solution() {}

std::string Solution::key() { return "solution"; }
std::string Solution::display() { return "Solution"; }

Challenge Solution::getChallengeFromString(const std::string input)
{
    std::locale loc;
    for (std::string::size_type i=0; i<input.length(); ++i)
        std::tolower(input[i],loc);

    if (input == "vowelsquare") {
        return Challenge::VowelSquare;
    } else if (input == "palindromenumber") {
        return Challenge::PalindromeNumber;
    } else if (input == "addtwonumbers") {
        return Challenge::AddTwoNumbers;
    } else if (input == "closestenemy") {
        return Challenge::ClosestEnemy;
    } else if (input == "laststoneweight") {
        return Challenge::LastStoneWeight;
    } else if (input == "stringsort") {
        return Challenge::StringSort;
    } else if (input == "isunique") {
        return Challenge::IsUnique;
    } else if (input == "arepermutations") {
        return Challenge::ArePermutations;
    } else if (input == "urlify") {
        return Challenge::Urlify;
    } else if (input == "palindromepermutation") {
        return Challenge::PalindromePermutation;
    } else if (input == "oneaway") {
        return Challenge::OneAway;
    } else if (input == "compressstring") {
        return Challenge::CompressString;
    } else if (input == "rotatematrix") {
        return Challenge::RotateMatrix;
    } else if (input == "zeromatrix") {
        return Challenge::ZeroMatrix;
    } else if (input == "stringrotation") {
        return Challenge::StringRotation;
    } else if (input == "removedups") {
        return Challenge::RemoveDups;
    } else if (input == "partition") {
        return Challenge::Partition;
    } else if (input == "sumlists") {
        return Challenge::SumLists;
    } else {
        return Challenge::Unspecified;
    }
}

