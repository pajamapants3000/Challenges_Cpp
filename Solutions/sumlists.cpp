#include "sumlists.h"

#include <string>
#include <tuple>
#include <vector>
#include <cmath>

#include "solution.h"
#include "solutionio.h"
#include "../linkedlist.h"

SumLists::SumLists() :
    Solution(),
    m_n1 {nullptr},
    m_n2 {nullptr},
    m_isReversed {false}
{}

SumLists::SumLists(std::string input) :
    Solution(),
    m_n1 {nullptr},
    m_n2 {nullptr},
    m_isReversed {false}
{
    setInput(input);
}

SumLists::~SumLists(){}

std::vector<std::tuple<std::string, std::string>> SumLists::testCases() const
{
    return {{ "", "0"},
        { "0, 1 2 3, 4 5 6", "975"},
        { "0, 7 6 7 3, 2 3", "3799"},
        { "0, 9 8 2 4, 7 8", "4376"},
        { "0, 7 8, 9 8 2 4", "4376"},
        { "1, 7 6 7 3, 2 3", "7696"},
        { "1, 9 8 2 4, 7 8", "9902"},
        { "1, 7 8, 9 8 2 4", "9902"}};
};

void SumLists::setInput(const std::string input)
{
    std::vector<std::vector<int>> in { extractMatrix<int>(input) };
    if (in.size() < 3) return;
    m_isReversed = in.at(0).at(0);
    m_n1 = DllNode<int>::fromArray(in.at(1));
    m_n2 = DllNode<int>::fromArray(in.at(2));
}

std::string SumLists::getSolution() const
{
    return to_string(sumlists(m_n1, m_n2, m_isReversed));
}

int SumLists::sumlists(const DllNode<int>* const n1, const DllNode<int>* const n2, bool isReversed)
{
    int sum {0};
    int order {0};
    const DllNode<int>* pNode1 {isReversed ? getLast(n1) : n1};
    const DllNode<int>* pNode2 {isReversed ? getLast(n2) : n2};
    while (pNode1 || pNode2) {
        if (!pNode1) {
            sum += pow(10, order++)*pNode2->val;
            pNode2 = isReversed ? pNode2->prev : pNode2->next;
        } else if (!pNode2) {
            sum += pow(10, order++)*pNode1->val;
            pNode1 = isReversed ? pNode1->prev : pNode1->next;
        } else {
            sum += pow(10, order++)*(pNode1->val + pNode2->val);
            pNode1 = isReversed ? pNode1->prev : pNode1->next;
            pNode2 = isReversed ? pNode2->prev : pNode2->next;
        }
    }
    return sum;
}

const DllNode<int>* SumLists::getLast(const DllNode<int>* head)
{
    const DllNode<int>* pNode {head};
    while (pNode->next) pNode = pNode->next;
    return pNode;
}
