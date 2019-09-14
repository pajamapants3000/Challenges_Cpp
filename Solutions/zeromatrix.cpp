#include "zeromatrix.h"

#include <string>
#include <vector>

ZeroMatrix::ZeroMatrix() :
    Solution(),
    m_a{}
{
}

ZeroMatrix::ZeroMatrix(std::string input) :
    Solution(),
    m_a{}
{
    setInput(input);
}

ZeroMatrix::~ZeroMatrix()
{
}

std::vector<std::tuple<std::string, std::string>> ZeroMatrix::testCases() const
{
    return {{ "3 0 2, 4 6 5", "0 0 0, 4 0 5"}, { "1 2 3 4, 5 6 7 8, 9 0 9 8", "1 0 3 4, 5 0 7 8, 0 0 0 0" }}
}

void ZeroMatrix::setInput(const std::string input)
{
    m_a = extractIntMatrix<int>(input, "ZeroMatrix");
}

std::string ZeroMatrix::getSolution() const
{
    std::vector<std::vector<int>> a { makeCopy(m_a) };
    zeroMatrix(a);
    return arrayToString(a);
}

void zeroMatrix(std::vector<std::vector<int>>& a)
{
    // TBC.
}

