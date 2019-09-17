#include "palindromenumber.h"

#include <iostream>
#include <string>
#include <stdexcept>

PalindromeNumber::PalindromeNumber(bool useNumericSolution) :
    Solution(),
    rawInput {},
    useNumericSolution { useNumericSolution },
    number {0}
{
}

PalindromeNumber::PalindromeNumber(std::string input, bool useNumericSolution) :
    Solution(),
    rawInput {},
    useNumericSolution { useNumericSolution },
    number {0}
{
    setInput(input);
}

PalindromeNumber::~PalindromeNumber(){}

std::vector<std::tuple<std::string, std::string>> PalindromeNumber::testCases() const
{
    return {{ "121", "true"}, { "-121", "false"}, { "10", "false"}};
}

void PalindromeNumber::setInput(const std::string input)
{
    rawInput = input;

    try {
        number = std::stoll(input); // throws exception on fail; see http://www.cplusplus.com/reference/string/stoll/
    } catch (const std::invalid_argument& ia) {
        std::cerr << "PalindromeNumber: Invalid input: " << ia.what() << "\n";
        throw;
    } catch (const std::out_of_range& oor) {
        std::cerr << "PalindromeNumber: Input out of range: " << oor.what() << "\n";
        throw;
    }
}

std::string PalindromeNumber::getSolution() const
{
    if (useNumericSolution) {
        return getNumericSolution();
    } else {
        return getStringSolution();
    }
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

    std::vector<int> digits{};

    while (workingNumber) {
        digits.insert(digits.begin(), workingNumber % 10);
        workingNumber /= 10;
    }

    for (std::vector<int>::size_type i{0}; i < digits.size(); ++i) {
        if (digits.at(i) != digits.at(digits.size() - 1 - i)) {
            return NOTAPALINDROME;
        }
    }

    return ISAPALINDROME;
}
