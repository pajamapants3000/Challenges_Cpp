#include "rotatematrix.h"

#include "solution.h"

RotateMatrix::RotateMatrix() :
    Solution(),
    m_M {nullptr},
    m_N {0},
    m_isClockwise {false}
{
}

RotateMatrix::RotateMatrix(std::string input) :
    Solution(),
    m_M {nullptr},
    m_N {0},
    m_isClockwise {false}
{
    setInput(input);
}

RotateMatrix::~RotateMatrix()
{
    for (size_t i {0}; i < m_N; ++i) {
        delete[] m_M[i];
    }
    delete[] m_M;
}

std::vector<std::tuple<std::string, std::string>> RotateMatrix::testCases() const
{
    return {{ "11 12 13 14, 21 22 23 24, 31 32 33 34, 41 42 43 44", "14 24 34 44, 13 23 33 43, 12 22 32 42, 11 21 31 41"},
            { "11 12 13 14 15, 21 22 23 24 25, 31 32 33 34 35, 41 42 43 44 45, 51 52 53 54 55", "15 25 35 45 55, 14 24 34 44 54, 13 23 33 43 53, 12 22 32 42 52, 11 21 31 41 51"}};
}

void RotateMatrix::setInput(const std::string input)
{
    extractMatrix(m_M, m_N, input);
}

std::string RotateMatrix::getSolution() const
{
    pix_t** M {copyMatrix(m_M, m_N, m_N)};
    rotateMatrix90(M, m_N, m_isClockwise);
    return matrixToString(M, m_N, m_N);
}

pix_t** RotateMatrix::copyMatrix(pix_t** m, const size_t rows, const size_t cols) const
{
    pix_t** result = new pix_t*[rows];
    for (size_t i {0}; i < rows; ++i) {
        result[i] = new pix_t[cols];
        for (size_t j {0}; j < cols; ++j) {
            result[i][j] = m[i][j];
        }
    }
    return result;
}

void RotateMatrix::setIsClockwise(bool isClockwise)
{
    m_isClockwise = isClockwise;
}

void RotateMatrix::rotateMatrix90(pix_t** M, const size_t N, const bool isClockwise)
{
    // we trust that M has NxN elements allocated
    pix_t temp;
    size_t row, col;
    pix_t* mm[4][4] {
        {&M[0][0], &M[0][1], &M[0][2], &M[0][3]},
        {&M[1][0], &M[1][1], &M[1][2], &M[1][3]},
        {&M[2][0], &M[2][1], &M[2][2], &M[2][3]},
        {&M[3][0], &M[3][1], &M[3][2], &M[3][3]},
    };
    for (size_t i {0}; 2*i < (N-1); ++i) {
        for (size_t j {0}; 2*j <= (N-1); ++j) {
            row = i;
            col = j;
            temp = M[row][col];
            for (int k {0}; k < RotationSetSize; ++k) {
                rotatePixel90(row, col, N, isClockwise);
                exch(temp, M[row][col]);
            }
        }
    }
}

void RotateMatrix::rotatePixel90(size_t &row, size_t &col, const size_t N, bool isClockwise)
{
    size_t temp {row};
    row = isClockwise ? col : N-1-col;
    col = isClockwise ? N-1-temp : temp;
}

void RotateMatrix::exch(pix_t &a, pix_t &b)
{
    pix_t temp {a};
    a = b;
    b = temp;
}
