/*
Add Two Numbers <https://leetcode.com/problems/add-two-numbers/>
Difficulty: Medium

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */
#ifndef ADDTWONUMBERS_H
#define ADDTWONUMBERS_H

#include "solution.h"

#include <string>
#include <vector>

class AddTwoNumbers : public Solution
{
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    AddTwoNumbers();
    explicit AddTwoNumbers(std::string input);
    virtual ~AddTwoNumbers() override;

    virtual std::string getSolution() const override;
    virtual std::vector<std::tuple<std::string, std::string>> testCases() const override;
    virtual void setInput(std::string input) override;

    std::vector<ListNode*> inputNumbers;

private:
    static std::vector<int> extractNumbers(const std::string &input);
    static ListNode* convertNumToLL(int num);
    void clearData();
};

#endif // ADDTWONUMBERS_H
