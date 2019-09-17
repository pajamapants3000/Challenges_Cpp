#include "addtwonumbers.h"

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

#include "solution.h"
#include "solutionio.h"

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

std::vector<std::tuple<std::string, std::string>> AddTwoNumbers::testCases() const
{
    return {{ "342 465", "807"}, { "239478 987238", "1226716"}, { "8723 12", "8735"}};
}

void AddTwoNumbers::setInput(const std::string input)
{
    clearData();

    std::vector<int> numbers = extractArray<int>(input);
    inputNumbers.push_back(convertNumToLL(numbers.at(0)));
    inputNumbers.push_back(convertNumToLL(numbers.at(1)));

    numbers.clear();
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
        carryTheOne = (tempNumber / 10);
        result = std::to_string(tempNumber % 10) + result;

        one = one->next;
        two = two->next;
    }

    while (one) {
        tempNumber = one->val + (carryTheOne ? 1 : 0);
        carryTheOne = (tempNumber / 10);
        result = std::to_string(tempNumber % 10) + result;

        one = one->next;
    }

    while (two) {
        tempNumber = two->val + (carryTheOne ? 1 : 0);
        carryTheOne = (tempNumber / 10);
        result = std::to_string(tempNumber % 10) + result;

        two = two->next;
    }
    if (carryTheOne) {
        result = '1' + result;
    }

    return result;
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

AddTwoNumbers::ListNode* AddTwoNumbers::convertNumToLL(int num)
{
    int working {num};

    ListNode *result { new ListNode(working % 10) };
    working /= 10;

    ListNode *llptr = result;
    while (working) {
        llptr->next = new ListNode(working % 10);
        llptr = llptr->next;
        working /= 10;
    }

    return result;
}
