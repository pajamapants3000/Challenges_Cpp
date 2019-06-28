#include "addtwonumbers.h"

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

AddTwoNumbers::AddTwoNumbers() :
    Solution(),
    inputNumbers{nullptr}
{
}

AddTwoNumbers::AddTwoNumbers(std::string input) :
    Solution(),
    inputNumbers{nullptr}
{
    setInput(input);
}

AddTwoNumbers::~AddTwoNumbers()
{
    clearData();
}

void AddTwoNumbers::clearData()
{
    for (ListNode *ll : inputNumbers) {
        while (ll) {
            ListNode* next = ll->next;
            delete ll;
            ll = next;
        }
    }

    inputNumbers.clear();
}

std::string AddTwoNumbers::getSolution() const
{
    bool carryTheOne{false};
    std::string result{};

    ListNode *one { inputNumbers.at(0) };
    ListNode *two { inputNumbers.at(1) };

    int tempNumber;
    while (one && two) {
        tempNumber = one->val + two->val + (carryTheOne ? 1 : 0);
        carryTheOne = (tempNumber % 10);
        result = std::to_string(tempNumber) + result;

        one = one->next;
        two = two->next;
    }

    while (one) {
        tempNumber = one->val + (carryTheOne ? 1 : 0);
        carryTheOne = (tempNumber % 10);
        result = std::to_string(tempNumber) + result;

        one = one->next;
    }

    while (two) {
        tempNumber = two->val + (carryTheOne ? 1 : 0);
        carryTheOne = (tempNumber % 10);
        result = std::to_string(tempNumber) + result;

        two = two->next;
    }

    return result;
}

std::vector<std::tuple<std::string, std::string>> AddTwoNumbers::testCases() const
{
    return {{ "342 465", "807"}, { "239478 987238", "1226716"}, { "8723 12", "8735"}};
}

void AddTwoNumbers::setInput(std::string input)
{
    clearData();

    std::vector<int> numbers = extractNumbers(input);
    inputNumbers.push_back(convertNumToLL(numbers.at(0)));
    inputNumbers.push_back(convertNumToLL(numbers.at(1)));

    numbers.clear();
}

AddTwoNumbers::ListNode* AddTwoNumbers::convertNumToLL(int num)
{
    int working {num};

    ListNode *result { new ListNode(working % 10) };
    ListNode *llptr = result;
    while (working) {
        working /= 10;
        llptr->next = new ListNode(working % 10);
        llptr = llptr->next;
    }

    return result;
}

std::vector<int> AddTwoNumbers::extractNumbers(const std::string &input)
{
    std::vector<int> result{};
    int num{0};
    std::string::size_type pos {0};

    try {
        num = std::stoi(input.substr(pos), &pos, 0); // stoi throws exception on fail; see http://www.cplusplus.com/reference/string/stoll/
        result.push_back(num);
        num = std::stoi(input.substr(pos), &pos, 0); // stoi throws exception on fail; see http://www.cplusplus.com/reference/string/stoll/
        result.push_back(num);
    } catch (const std::invalid_argument& ia) {
        std::cerr << "PalindromeNumber: Invalid input: " << ia.what() << "\n";
        exit(1);
    } catch (const std::out_of_range& oor) {
        std::cerr << "PalindromeNumber: Input out of range: " << oor.what() << "\n";
        exit(1);
    } catch (const std::exception& ex) {
        std::cerr << "PalindromeNumber: " << ex.what() << "\n";
        exit(1);
    } catch (...) {
        std::cerr << "PalindromeNumber: Failed to parse number from input.\n";
        exit(1);
    }

    return result;
}
