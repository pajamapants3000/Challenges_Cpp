/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true

Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Follow up:

Could you solve it without converting the integer to a string?
*/

#ifndef PALINDROMENUMBER_H
#define PALINDROMENUMBER_H

#include "solution.h"

#include <string>
#include <vector>
#include <tuple>

enum class STOLL_ERROR { SUCCESS, OVERFLOW, UNDERFLOW, INCONVERTIBLE };

const static std::string ISAPALINDROME { "true" };
const static std::string NOTAPALINDROME { "false" };

class PalindromeNumber : public Solution
{
public:
    explicit PalindromeNumber(bool useNumericSolution = true);
    explicit PalindromeNumber(std::string input, bool useNumericSolution = true);
    virtual ~PalindromeNumber();

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const override;
    virtual void setInput(const std::string input) override;
    virtual std::string getSolution() const override;

    virtual std::string key() override { return "palindromenumber"; }
    virtual std::string display() override { return "PalindromeNumber"; }

protected:
    std::string getStringSolution() const;
    std::string getNumericSolution() const;

private:
    std::string rawInput;
    bool useNumericSolution;
    std::int64_t number;
};

#endif // PALINDROMENUMBER_H
