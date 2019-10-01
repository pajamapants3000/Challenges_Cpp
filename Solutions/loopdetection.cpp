// NOTE: There is no good way to set this up from command line input, so I am
// simply hard-coding some examples that can be referenced as "testX" where X=1, 2, 3, ...
#include "loopdetection.h"

#include <string>
#include <tuple>
#include <vector>

#include "solutionio.h"
#include "../linkedlist.h"

LoopDetection::LoopDetection() :
    Solution(),
    m_pHead {nullptr},
    m_testName {}
{}

    LoopDetection::LoopDetection(std::string input) :
    Solution(),
    m_pHead {nullptr},
    m_testName {}
{
    setInput(input);
}

LoopDetection::~LoopDetection(){}

node_t* LoopDetection::getTestCase(std::string testName)
{
    size_t val {0};
    size_t loopSize {5};
    node_t* result { new node_t(val++) };
    node_t* pNode { result };

    if (testName == "test0") {      // no loop
        for (size_t i {0}; i < 5; ++i) {
            pNode->next = new node_t(val++);
            pNode = pNode->next;
        }
        pNode->next = nullptr;
        return result;
    } else if (testName == "test1") {   // loop starts at index 3
        for (size_t i {0}; i < (loopSize-2); ++i) {
            pNode->next = new node_t(val++);
            pNode = pNode->next;
        }
    } else if (testName == "test2" || testName == "test3") {   // loop starts at index 5
        for (size_t i {0}; i < loopSize; ++i) {
            pNode->next = new node_t(val++);
            pNode = pNode->next;
        }
    } else if (testName == "test4") {   // loop starts at index 7
        for (size_t i {0}; i < (loopSize+2); ++i) {
            pNode->next = new node_t(val++);
            pNode = pNode->next;
        }
    } else return nullptr;

    node_t* loopStart {pNode};
    if (testName == "test3") {  // loop size 1
        // don't add any loop nodes
    } else {
        for (size_t i {1}; i < loopSize; ++i) {
            pNode->next = new node_t(val++);
            pNode = pNode->next;
        }
    }
    pNode->next = loopStart;
    return result;
}

std::vector<std::tuple<std::string, std::string>> LoopDetection::testCases() const
{
    return {{ "test0", "no loop"},
        { "test1", "3"},
        { "test2", "5"},
        { "test3", "5"},
        { "test4", "7"},
        { "test5", "no such test"}};
};

void LoopDetection::setInput(const std::string input)
{
    m_testName = input;
    m_pHead = getTestCase(input);
}

std::string LoopDetection::getSolution() const
{
    if (!m_pHead) return "no such test";

    const node_t* pNode = detectLoop(m_pHead);
    if (!pNode) return "no loop";
    else return to_string(node_t::getIndex(m_pHead, pNode));
}

const node_t* LoopDetection::detectLoop(const node_t* const pHead)
{
    if (!pHead || !pHead->next) return nullptr;
    size_t m {0};
    size_t loopSize { stepsToOvertake(pHead) };
    if (loopSize == 0) return nullptr;
    const node_t* pNode { node_t::advance(pHead, loopSize) };
    m = loopSize / stepsToOvertake(pNode);
    loopSize /= m;
    const node_t* pNewHead {pHead};
    while (m==1) {
        node_t* pTemp { new node_t() };
        pTemp->next = const_cast<node_t*>(pNewHead);
        pNewHead = pTemp;
        m = stepsToOvertake(pNewHead) / loopSize;
    }
    pNode = pNewHead;
    while (m>1) {
        pNode = pNode->next;
        m = stepsToOvertake(pNode) / loopSize;
    }
    pNode = node_t::advance(pNode, loopSize);
    while (pNewHead != pHead) {
        node_t* pTemp { pNewHead->next };
        delete pNewHead;
        pNewHead = pTemp;
    }
    return pNode;
}

size_t LoopDetection::stepsToOvertake(const node_t* const pHead)
{
    if (!pHead || !pHead->next) return 0;
    const node_t* p1 {pHead};
    const node_t* p2 {pHead};
    size_t result {0};
    do {
        p1 = node_t::advance(p1, 1);
        p2 = node_t::advance(p2, 2);
        ++result;
    } while (p2 && p2->next && p1!=p2);
    if (p1==p2) return result;
    return 0;
}
