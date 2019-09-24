/*
Challenge
Have the function VowelSquare(input) take the input parameter being passed which will be a 2D matrix of some arbitrary size filled with letters from the alphabet, and determine if a 2x2 square composed entirely of vowels exists in the matrix. For example: input is ["abcd", "eikr", "oufj"] then this matrix looks like the following:

a b c d
e i k r
o u f j

Within this matrix there is a 2x2 square of vowels starting in the second row and first column, namely, ei, ou. If a 2x2 square of vowels is found your program should return the top-left position (row-column) of the square, so for this example your program should return 1-0. If no 2x2 square of vowels exists, then return the string not found. If there are multiple squares of vowels, return the one that is at the most top-left position in the whole matrix. The input matrix will at least be of size 2x2.
Sample Test Cases

Input:{"aqrst", "ukaei", "ffooo"}

Output:"1-2"

Input:{"gg", "ff"}

Output:"not found"
*/

/*
 * Assumptions:
 * Square input
 * Input no greater than 16x16 (should increase by increasing inputMaxChar)
*/

#ifndef VOWELSQUARE_H
#define VOWELSQUARE_H

#include <string>
#include <tuple>
#include <vector>

#include "solution.h"

class VowelSquare : public Solution
{
public:
    VowelSquare();
    explicit VowelSquare(std::string input);
    virtual ~VowelSquare() override;

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const override;
    virtual void setInput(const std::string input) override;
    virtual std::string getSolution() const override;

    virtual std::string key() override { return "vowelsquare"; }
    virtual std::string display() override { return "VowelSquare"; }

private:
    std::vector<std::string> extractInput(std::string &input);
    void trim(std::string &toTrim) const;
    bool isVowelSquare(size_t rowIndex, size_t colIndex) const;
    bool isVowel(char c) const;
    std::string getResult(size_t rowIndex, size_t colIndex) const;

    std::vector<std::string> matrix;
};

#endif // VOWELSQUARE_H
