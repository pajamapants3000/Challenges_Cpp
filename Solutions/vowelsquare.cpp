#include "vowelsquare.h"

#include <sstream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cctype>

#include "solution.h"

constexpr char NOT_FOUND[] { "not found" };

VowelSquare::VowelSquare() : Solution() { }

VowelSquare::VowelSquare(std::string input) : Solution()
{
    setInput(input);
}

VowelSquare::~VowelSquare() { }

std::vector<std::tuple<std::string, std::string>> VowelSquare::testCases() const
{
    return {{ "aaaa, aaaa, aaaa", "0-0"}, { "aqrst, ukaei, ffooo", "1-2"}, { "gg, ff", "not found"}};
};

void VowelSquare::setInput(std::string input)
{
    rawInput = input;
    matrix = extractInput(input);
}

std::string VowelSquare::getSolution() const
{
    size_t rowCount { matrix.size() };
    size_t colCount { matrix.at(0).length() };
    size_t largestDim { rowCount > colCount ? rowCount : colCount };
    size_t smallestDim { rowCount < colCount ? rowCount : colCount };

    /*
        We want to prefer upper-left results, upper being more important to left-most, so we sweep diagonally from the top left with increasing radius
        Some other considerations:
            We don't need to check the last row/column (we are looking for an upper-left element of a 2x2 square)
            We scan a column, then a row, then the diagonal (having stopped one short on the row/column to skip the diagonal being evaluated twice).
    */
    size_t rowCountEffective { rowCount - 1 };
    size_t colCountEffective { colCount - 1 };

    for (size_t index{0}; index < largestDim-1; ++index) {

        size_t rowLimit { rowCountEffective < (index+1) ? rowCountEffective : index };
        size_t colLimit { colCountEffective < (index+1) ? colCountEffective : index };
        if (index < colCountEffective) {
            for (size_t rowIndex {0}; rowIndex < rowLimit; ++rowIndex) {
                if (isVowelSquare(rowIndex, index)) {
                    return getResult(rowIndex, index);
                }
            }
        }
        if (index < rowCountEffective) {
            for (size_t colIndex {0}; colIndex < colLimit; ++colIndex) {
                if (isVowelSquare(index, colIndex)) {
                    return getResult(index, colIndex);
                }
            }
        }
        if (index < (smallestDim-1)) {
            if (isVowelSquare(index, index)) {
                return getResult(index, index);
            }
        }
    }

    return NOT_FOUND;
}

bool VowelSquare::isVowelSquare(size_t rowIndex, size_t colIndex) const
{
    if (isVowel(matrix[rowIndex][colIndex])
            && isVowel(matrix[rowIndex+1][colIndex])
            && isVowel(matrix[rowIndex][colIndex+1])
            && isVowel(matrix[rowIndex+1][colIndex+1])) {
        return true;
    }
    return false;
}

bool VowelSquare::isVowel(char c) const
{
    switch(c)
    {
    case 'a': case 'e': case 'i': case 'o': case 'u':
    case 'A': case 'E': case 'I': case 'O': case 'U':
        return true;
    }
    return false;
}

std::string VowelSquare::getResult(size_t rowIndex, size_t colIndex) const
{
    std::stringstream stream {};
    stream << rowIndex << "-" << colIndex;
    std::string result;
    stream >> result;
    return result;
}

std::vector<std::string> VowelSquare::extractInput(std::string &inputJoined)
{
    std::string temp;
    std::vector<std::string> extracted;

    std::stringstream stream { inputJoined };
    while (getline(stream, temp, ','))
    {
        trim(temp);
        extracted.push_back(temp);
    }

    return extracted;
}

void VowelSquare::trim(std::string &s) const
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) { return !std::isspace(ch); }));
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) { return !std::isspace(ch); }).base(), s.end());
}
