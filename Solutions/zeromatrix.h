#ifndef ZEROMATRIX_H
#define ZEROMATRIX_H

#include "solution.h"

#include <string>
#include <vector>

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

};

#endif // ZEROMATRIX_H
