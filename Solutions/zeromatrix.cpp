#include "zeromatrix.h"

#include <string>
#include <vector>

#include "solutionio.h"

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
    return {{ "", "", },
            {"3 0 2, 4 6 5", "0 0 0, 4 0 5"},
            { "1 2 3 4, 5 6 7 8, 9 0 9 8", "1 0 3 4, 5 0 7 8, 0 0 0 0" }};
}

void ZeroMatrix::setInput(const std::string input)
{
    m_a = extractMatrix<int>(input, "ZeroMatrix");
}

std::string ZeroMatrix::getSolution() const
{
    std::vector<std::vector<int>> a { matrixCopy<int>(m_a) };
    zeroMatrix(a);
    return to_string(a);
}

void ZeroMatrix::zeroMatrix(std::vector<std::vector<int>>& a)
{
    if (a.size() == 0) return;

    rowsize_t N { a.at(0).size() };     // # of columns
    colsize_t M { a.size() };           // # of rows
    bool hasZeroInRowZero { false };
    bool hasZeroInColZero { false };

    for (colsize_t i {0}; i < M; ++i) {     // over rows
        for (rowsize_t j {0}; j < N; ++j) { // over columns
            if (a.at(i).at(j) == 0) {
                if (!(i==0 || j==0)) {  // don't zero-out row-0 and col-0 until later
                    zeroRow(a.at(i));   // can safely zero-out row now
                    a.at(0).at(j) = 0;      // mark column to zero-out later
                } else {
                    if (i==0) hasZeroInRowZero = true;
                    if (j==0) hasZeroInColZero = true;
                }
                break;  // done with this row
            }
        }
    }

    row_t &rowZero { a.at(0) };
    for (rowsize_t j {0}; j < N; ++j) {     // over columns of row-0
        if (rowZero.at(j) == 0) {
            zeroCol(a, j);
        }
    }

    // finally, zero-out row-0 and/or col-0 if needed
    if (hasZeroInRowZero) zeroRow(a.at(0));
    if (hasZeroInColZero) zeroCol(a, 0);
}

void ZeroMatrix::zeroRow(std::vector<int>& a)
{
    for (rowsize_t i {0}; i < a.size(); ++i) {
        a.at(i) = 0;
    }
}

void ZeroMatrix::zeroCol(std::vector<std::vector<int>>& a,
    typename std::vector<std::vector<int>>::size_type column)
{
    for (colsize_t i {0}; i < a.size(); ++i) {
        a.at(i).at(column) = 0;
    }
}


