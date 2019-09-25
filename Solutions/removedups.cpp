#include "removedups.h"

#include <string>
#include <tuple>
#include <vector>

#include "solution.h"
#include "solutionio.h"
#include "../linkedlist.h"

RemoveDups::RemoveDups() :
    Solution(),
    m_pHead {nullptr}
{}

RemoveDups::RemoveDups(std::string input) :
    Solution(),
    m_pHead {nullptr}
{
    setInput(input);
}

RemoveDups::~RemoveDups()
{
    m_pHead->clearMem();
}

std::vector<std::tuple<std::string, std::string>> RemoveDups::testCases() const
{
    return {{ "", ""},
        { "a r t d r d c w", "a r t d c w"},
        { "a b a b a b a b a b", "a b"}};
};

void RemoveDups::setInput(const std::string input)
{
    std::vector<char> a { extractArray<char>(input, display()) };
    m_pHead = DllNode<char>::fromArray(a);
}

std::string RemoveDups::getSolution() const
{
    DllNode<char>* copy { DllNode<char>::fromArray(DllNode<char>::toArray(m_pHead)) };
    removedups(copy);
    return arrayToString(DllNode<char>::toArray(copy));
}

void RemoveDups::removedups(DllNode<char>* pHead)
{
    bool ht[alphabetSize];
    for (int i {0}; i < alphabetSize; ++i) ht[i] = false;

    DllNode<char>* pNode {pHead};
    while (pNode) {
        if (hasValue(ht, pNode->val)) pNode = DllNode<char>::deleteNode(pNode);
        else {
            addValue(ht, pNode->val);
            pNode = DllNode<char>::advance(pNode);
        }
    }
}

bool hasValue(bool* ht, char val)
{
    return ht[static_cast<int>(val)];
}

void addValue(bool* ht, char val)
{
    ht[static_cast<int>(val)] = true;
}
