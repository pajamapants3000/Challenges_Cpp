#include "stringsort.h"

#include <vector>
#include <iostream>

#include "../sort.h"

static SortAlgorithm algorithm { SortAlgorithm::Heap };

StringSort::StringSort() :
    Solution(),
    m_sorter {nullptr}
{ }

StringSort::StringSort(const std::string input) :
    Solution(),
    m_sorter {nullptr}
{
    setInput(input);
}

StringSort::~StringSort()
{
    m_sorter->~Sort();
}

std::vector<std::tuple<std::string, std::string>> StringSort::testCases() const
{
    return {{ "testable", "abeelstt"}, { "zyxwvut", "tuvwxyz"}, { "1864", "1468"},
            {"1", "1"}, {"21", "12"}, {"321", "123"}, {"54321", "12345"}, {"654321", "123456"},
            {"7654321", "1234567"}, {"87654321", "12345678"}, {"987654321", "123456789"},
            {"10987654321", "01123456789"}, {"1110987654321", "0111123456789"}, {"121110987654321", "011111223456789"},
            {"13121110987654321", "01111112233456789"}, {"1413121110987654321", "0111111122334456789"}, {"151413121110987654321", "011111111223344556789"},
            { "antidisestablishmentarianism", "aaaabdeehiiiiilmmnnnrssssttt"},
            { "antidisestablishmentarianismantidisestablishmentarianism", "aaaaaaaabbddeeeehhiiiiiiiiiillmmmmnnnnnnrrsssssssstttttt"}};
}

void StringSort::setInput(const std::string input)
{
    size_t N = input.size();

    char* a = new (std::nothrow) char[N+1];
    if (!a) throw "failed to allocate memory for input storage.";

    for (size_t i {0}; i < N; ++i) {
        a[i] = input.at(i);
    }

    m_sorter = new Sort<char>(a, N, algorithm);
}

std::string StringSort::getSolution() const
{
    char* a { m_sorter->getSorted() };
    std::string result;
    result.append(a, m_sorter->size());
    return result;
}
