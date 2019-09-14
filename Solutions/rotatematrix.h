#ifndef ROTATEMATRIX_H
#define ROTATEMATRIX_H

#include "solution.h"

#include <string>
#include <tuple>
#include <vector>

using pix_t = std::uint32_t;
using size_t = std::size_t;

constexpr int FullRotation {360};
constexpr int Rotation {90};
constexpr int RotationSetSize { FullRotation / Rotation }; // technically it should be the lowest common multiple of FullRotation and Rotation divided by Rotation

class RotateMatrix : public Solution
{
public:
    RotateMatrix();
    explicit RotateMatrix(std::string input);
    virtual ~RotateMatrix() override;

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const override;
    virtual void setInput(const std::string input) override;
    virtual std::string getSolution() const override;

    static void rotateMatrix90(pix_t** M, const size_t N, const bool isClockwise);

    void setIsClockwise(bool isClockwise);
private:
    pix_t** m_M;
    size_t m_N;
    bool m_isClockwise;

    static void rotatePixel90(size_t &row, size_t &col, const size_t N, bool isClockwise);
    static void exch(pix_t &a, pix_t &b);

    pix_t** copyMatrix(pix_t** m, const size_t rows, const size_t cols) const;
};

#endif // ROTATEMATRIX_H
