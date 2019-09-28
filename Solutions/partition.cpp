#include "partition.h"

#include <string>
#include <tuple>
#include <vector>

#include "solution.h"
#include "solutionio.h"
#include "../linkedlist.h"

Partition::Partition() :
    Solution(),
    m_list {nullptr},
    m_part {0}
{}

Partition::Partition(std::string input) :
    Solution(),
    m_list {nullptr},
    m_part {0}
{
        setInput(input);
}

Partition::~Partition(){}

std::vector<std::tuple<std::string, std::string>> Partition::testCases() const
{
    return {{ "", ""},
        { "1 2 3 4 5", ""},
        { "4, 1 2 3 4 5", "1 2 3 4 5"},
        { "4, 5 4 3 2 1", "3 2 1 5 4"}};
};

void Partition::setInput(const std::string input)
{
    std::vector<std::vector<int>> in { extractMatrix<int>(input) };
    if (in.size() < 2) return;
    else {
        m_list = SllNode<int>::fromArray(in.at(1));
        m_part = in.at(0).at(0);
    }
}

std::string Partition::getSolution() const
{
    SllNode<int>* dummy { new SllNode<int>() };
    dummy->next = m_list;
    partition(dummy, m_part);
    return to_string(SllNode<int>::toArray(dummy->next));
}

void Partition::partition(SllNode<int>* in, int part)
{
    SllNode<int>::partition(in, part);
}

