#ifndef ZEROMATRIX_H
#define ZEROMATRIX_H

#include "solution.h"

#include <string>
#include <vector>

using row_t = std::vector<int>;
using matrix_t = std::vector<std::vector<int>>;
using rowsize_t = typename row_t::size_type;
using colsize_t = typename matrix_t::size_type;

class ZeroMatrix : public Solution
{
public:
    ZeroMatrix();
    explicit ZeroMatrix(std::string input);
    virtual ~ZeroMatrix() override;

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const override;
    virtual void setInput(const std::string input) override;
    virtual std::string getSolution() const override;

    static void zeroMatrix(std::vector<std::vector<int>>& a);

private:
    std::vector<std::vector<int>> m_a;

    static void zeroRow(std::vector<int>& a);
    static void zeroCol(std::vector<std::vector<int>>& a,
        typename std::vector<std::vector<int>>::size_type column);
};

#endif // ZEROMATRIX_H
