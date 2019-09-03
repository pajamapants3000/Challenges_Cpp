#include "urlify.h"

#include <string>
#include <vector>
#include <tuple>

Urlify::Urlify() :
    Solution(),
    m_s {},
    m_N {}
{
}

Urlify::Urlify(std::string input) :
    Solution(),
    m_s {},
    m_N {}
{
    setInput(input);
}

Urlify::~Urlify() {}

std::vector<std::tuple<std::string, std::string>> Urlify::testCases() const
{
    return { {"Mr John Smith    ;", "Mr%20John%20Smith"}, {"", ""} };
}

void Urlify::setInput(const std::string input)
{
    m_s.clear();
    m_N = 0;

    if (input.size() == 0 || input.at(input.size()-1) != ';') return;

    urlsize_t extraSpaces {0};
    std::string::const_iterator cit {input.cbegin()};
    std::string::const_iterator end {input.cend()};
    while (cit != end) {
        m_s.push_back(*cit);
        if (*cit == ' ') ++extraSpaces;
        else extraSpaces = 0;
        ++cit;
        if (*cit == ';' && next(cit, 1) == end) break;
    }
    m_N = m_s.size() - extraSpaces;
}

std::string Urlify::getSolution() const
{
    std::string result {m_s};

    urlify(result, m_N);
    return result;
}

void Urlify::urlify(std::string &s, const urlsize_t N)
{
    urlsize_t spaceCount { countSpaces(s, N) };
    // assert that s.size() >= N + 2*spaceCount
    for (urlsize_t i {N-1}; spaceCount>0 && i!=0; --i) {
        if (s.at(i) == ' ') {
            --spaceCount;
            writeUrlSpace(s, i+2*spaceCount);
        } else {
            s.at(i+2*spaceCount) = s.at(i);
        }
    }
    // assert that spaceCount == 0
}

urlsize_t Urlify::countSpaces(const std::string s, const urlsize_t N)
{
    urlsize_t result {0};
    for (urlsize_t i {0}; i < N; ++i) {
        if (s.at(i) == ' ') ++result;
    }
    return result;
}

void Urlify::writeUrlSpace(std::string &s, const urlsize_t index)
{
    for (urlsize_t i {0}; i < urlSpace.size(); ++i) {
        s.at(index+i) = urlSpace.at(i);
    }
}

