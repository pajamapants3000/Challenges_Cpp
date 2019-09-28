/*
SumLists
Add two numbers represented by linked lists, with each node holding a single digit, little-endian-like. Repeat for big-endian (largest magnitude first).

Sample Test Cases

Input: example_input

Output: example_output

*/

/*
 * Assumptions:
 * all digits are 0-9 integers; if there are n nodes, the value represented by the list is order of magnitude n (e.g. 2-3 represents either 23 or 32, not e.g. 3200 or anything like that)
*/

#ifndef SUMLISTS_H
#define SUMLISTS_H

#include <string>
#include <tuple>
#include <vector>

#include "solution.h"
#include "../linkedlist.h"

class SumLists : public Solution
{
public:
    SumLists();
    explicit SumLists(std::string input);
    virtual ~SumLists() override;

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const override;
    virtual void setInput(const std::string input) override;
    virtual std::string getSolution() const override;

    virtual std::string key() override { return "sumlists"; }
    virtual std::string display() override { return "SumLists"; }

    static int sumlists(const DllNode<int>* const n1, const DllNode<int>* const n2, bool isReversed);

private:
    DllNode<int>* m_n1;
    DllNode<int>* m_n2;
    bool m_isReversed;

    static const DllNode<int>* getLast(const DllNode<int>* head);
};

#endif // SUMLISTS_H
