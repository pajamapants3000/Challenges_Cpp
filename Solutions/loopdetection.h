/*
LoopDetection
Given a (single-)linked list, determine whether the list contains a cycle, and, if so, find the start of the loop.

Sample Test Cases

Input: 1 2 3 4 5 3 4 5 3 ...

Output: 3

*/

/*
 * Assumptions:
 * Data type stored in node is size_t, though it is irrelevant to solution.
*/

#ifndef LOOPDETECTION_H
#define LOOPDETECTION_H

#include <string>
#include <tuple>
#include <vector>

#include "solution.h"

#include "../linkedlist.h"

using node_t = SllNode<size_t>;

class LoopDetection : public Solution
{
public:
    LoopDetection();
    explicit LoopDetection(std::string input);
    virtual ~LoopDetection() override;

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const override;
    virtual void setInput(const std::string input) override;
    virtual std::string getSolution() const override;

    virtual std::string key() override { return "loopdetection"; }
    virtual std::string display() override { return "LoopDetection"; }

    static const node_t* detectLoop(const node_t* const pHead);
    static size_t stepsToOvertake(const node_t* const pHead);

private:
    node_t* m_pHead;
    std::string m_testName;

    node_t* getTestCase(std::string testName);
};

#endif // LOOPDETECTION_H
