#include "palindromenumber.h"

#include <string>

PalindromeNumber::PalindromeNumber(bool useNumericSolution) :
    Solution(),
    useNumericSolution { useNumericSolution },
    number {0}
{
}

PalindromeNumber::PalindromeNumber(std::string input, bool useNumericSolution) :
    Solution(),
    useNumericSolution { useNumericSolution },
    number {0}
{
    setInput(input);
}

PalindromeNumber::~PalindromeNumber(){}

std::string PalindromeNumber::getSolution() const
{
    if (useNumericSolution) {
        return getNumericSolution();
    } else {
        return getStringSolution();
    }
}

std::vector<std::tuple<std::string, std::string>> PalindromeNumber::testCases() const
{
    return {{ "121", "true"}, { "-121", "false"}, { "10", "false"}};
}

void PalindromeNumber::setInput(std::string input)
{
    rawInput = input;
    number = std::stoll(input); // throws exception on fail; see http://www.cplusplus.com/reference/string/stoll/
}

std::string PalindromeNumber::getStringSolution() const
{
    for (ulong i{0}; i < (rawInput.length() / 2); ++i) {
        if (rawInput[i] != rawInput[rawInput.length() - 1 - i]) {
            return NOTAPALINDROME;
        }
    }

    return ISAPALINDROME;
}

std::string PalindromeNumber::getNumericSolution() const
{
    if (number < 0) return NOTAPALINDROME;

    std::int64_t workingNumber { number };

    std::vector<int> digits { static_cast<int>(workingNumber % 10) };

    while (workingNumber) {
        workingNumber /= 10;
        digits.push_back(workingNumber % 10);
    }

    for (std::vector<int>::size_type i{0}; i < digits.size(); ++i) {
        if (digits.at(i) != digits.at(digits.size() - 1 - i)) {
            return NOTAPALINDROME;
        }
    }

    return ISAPALINDROME;
}
