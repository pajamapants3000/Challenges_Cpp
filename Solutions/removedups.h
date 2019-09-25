/*
RemoveDups
Write code to remove duplicates from an unsorted linked list.
FOLLOW UP: How would you solve this problem if a temporary buffer is not allowed?

Sample Test Cases

Input: a - r - t - d - r - d - c - w

Output: a - r - t - d - c - w

*/

/*
 * Assumptions:
 * Linked List is double-linked
 * Values are characters (can generalize if needed)
 * List initially unsorted.
*/

#ifndef REMOVEDUPS_H
#define REMOVEDUPS_H

#include <string>
#include <tuple>
#include <vector>

#include "solution.h"
#include "../linkedlist.h"

const int alphabetSize {128};

class RemoveDups : public Solution
{
public:
    RemoveDups();
    explicit RemoveDups(std::string input);
    virtual ~RemoveDups() override;

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const override;
    virtual void setInput(const std::string input) override;
    virtual std::string getSolution() const override;

    virtual std::string key() override { return "removedups"; }
    virtual std::string display() override { return "RemoveDups"; }

    static void removedups(DllNode<char>* pHead);

private:
    DllNode<char>* m_pHead;
};

bool hasValue(bool* ht, char val);
void addValue(bool* ht, char val);

#endif // REMOVEDUPS_H

