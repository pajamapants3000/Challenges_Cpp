
#include "solution.h"

#include <cmath>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::vector<int> Solution::extractIntegers(const std::string &input, const std::string &caller)
{
    std::string _caller { caller.empty() ? "Solution" : caller };

    std::vector<int> result{};
    int num{0};
    std::string::size_type pos {0};

    try {
        while (pos != input.length()) {
            num = std::stoi(input.substr(pos), &pos, 0); // stoi throws exception on fail; see http://www.cplusplus.com/reference/string/stoll/
            result.push_back(num);
        }
    } catch (const std::invalid_argument& ia) {
        std::cerr << _caller << ": Invalid input: " << ia.what() << "\n";
        exit(1);
    } catch (const std::out_of_range& oor) {
        std::cerr << _caller << ": Input out of range: " << oor.what() << "\n";
        exit(1);
    } catch (const std::exception& ex) {
        std::cerr << _caller << ": " << ex.what() << "\n";
        exit(1);
    } catch (...) {
        std::cerr << _caller << ": Failed to parse number from input.\n";
        exit(1);
    }

    return result;
}

std::vector<std::string> Solution::extractStrings(const std::string &input, const std::string &caller)
{
    std::string _caller { caller.empty() ? "Solution" : caller };

    std::vector<std::string> result {};

    std::string::const_iterator citer { input.cbegin() };
    std::string::const_iterator next { nullptr };
    std::string::const_iterator end { input.cend() };

    while (citer != end) {
        next = std::find_if(citer, end, [](const char c){ return isspace(c) || (c == ','); });

        result.push_back(std::string { citer, next });
        citer = next;

        while (isspace(*citer) || (*citer == ',')) { ++citer; }
    }

    return result;
}

std::vector<std::vector<int>> Solution::extractIntMatrix(const std::string &input, const std::string &caller)
{
    using row_t = std::vector<int>;
    using matrix_t = std::vector<row_t>;

    std::string _caller { caller.empty() ? "Solution" : caller };
    matrix_t result {};

    row_t::size_type rowsize {0};
    matrix_t::size_type currentRow {0};
    for (std::string::size_type i {0}; i < input.length(); ++i) {
        row_t nextRow{};
        result.push_back(nextRow);

        while (i < input.length() && !isspace(input.at(i)) && (input.at(i) != ',')) {
            result.at(currentRow).push_back(static_cast<int>(input.at(i) - '0'));
            ++i;
        }

        if (rowsize > 0 && result.at(currentRow).size() != rowsize) {
            std::cerr << _caller << "::extractIntMatrix - Invalid input: rows must be the same length.\n";
            exit(1);
        }

        while (i < input.length() && isspace(input.at(i) || (input.at(i) == ','))) { ++i; }

        ++currentRow;
    }

    return result;
}

std::vector<std::vector<char>> Solution::extractCharMatrix(const std::string &input, const std::string &caller)
{
    using row_t = std::vector<char>;
    using matrix_t = std::vector<row_t>;

    std::string _caller { caller.empty() ? "Solution" : caller };
    std::vector<std::vector<char>> result {};

    matrix_t::size_type currentRow {0};
    for (std::string::size_type i {0}; i < input.length(); ++i) {
        row_t nextRow{};
        result.push_back(nextRow);

        while (!isspace(input.at(i) && (input.at(i) != ','))) {

            if (!('a' <= input.at(i) && input.at(i) <= 'z') ||
                ('A' <= input.at(i) && input.at(i) <= 'Z') ||
                ('0' <= input.at(i) && input.at(i) <= '9')) {

                std::cerr << _caller << ": Invalid input - characters must be alphanumeric.\n";
                exit(1);
            }

            result.at(currentRow).push_back(input.at(i));
            ++i;
        }

        while (isspace(input.at(i) || (input.at(i) == ','))) { ++i; }
    }

    return result;
}
