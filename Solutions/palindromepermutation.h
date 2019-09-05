#ifndef PALINDROMEPERMUTATION_H
#define PALINDROMEPERMUTATION_H

#include "solution.h"

#include <string>
#include <vector>
#include <tuple>


class PalindromePermutation : public Solution
{
public:
    PalindromePermutation();
    explicit PalindromePermutation(std::string input);
    virtual ~PalindromePermutation() override;

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const override;
    virtual void setInput(const std::string input) override;
    virtual std::string getSolution() const override;

    static bool palindromePermutation(const std::string s);

private:
    std::string m_s;
};

#endif // PALINDROMEPERMUTATION_H
