/*
Palindrome
Implement a function to check if a linked list is a palindrome

Sample Test Cases

Input: i-s-a-p-a-l-a-p-a-s-i

Output: true

*/

/*
 * Assumptions:
 * Though not specified, the single-linked-list problem is far more interesting
 * Will also assume values are type char.
*/

#ifndef PALINDROME_H
#define PALINDROME_H

#include <string>
#include <tuple>
#include <vector>

#include "solution.h"

#include "../linkedlist.h"

class Palindrome : public Solution
{
public:
    Palindrome();
    explicit Palindrome(std::string input);
    virtual ~Palindrome() override;

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const override;
    virtual void setInput(const std::string input) override;
    virtual std::string getSolution() const override;

    virtual std::string key() override { return "palindrome"; }
    virtual std::string display() override { return "Palindrome"; }

    static bool isPalindrome(const SllNode<char>* head);

private:
    SllNode<char>* m_head;

    static const SllNode<char>* palindrome(const SllNode<char>* head, const size_t N, const size_t NMax);
};

#endif // PALINDROME_H
