#include "oneaway.h"

#include <sstream>

OneAway::OneAway() :
    Solution(),
    m_s1 {},
    m_s2 {}
{}

OneAway::OneAway(std::string input) :
    Solution(),
    m_s1 {},
    m_s2 {}
{}

OneAway::~OneAway()
{

}

std::vector<std::tuple<std::string, std::string>> OneAway::testCases() const
{
    return { {"pale ple", "true"}, {"pales pale", "true"}, {"pale bale", "true"}, {"pale bake", "false"},
        {"", "true"}, {"a", "true"} };
}

void OneAway::setInput(const std::string input)
{
    std::vector<std::string> split;
    std::stringstream stream {input};
    std::string next;

    int i {0};
    while (i<2 && getline(stream, next, ' ')) {
        split.push_back(next);
        ++i;
    }

    if (i > 0) m_s1 = split.at(0);
    else m_s1 = std::string();

    if (i > 1) m_s2 = split.at(1);
    else m_s2 = std::string();
}

std::string OneAway::getSolution() const
{
    return oneAway(m_s1, m_s2) ? "true" : "false";
}

bool OneAway::oneAway(const std::string s1, const std::string s2)
{
    std::string s1l { (s2.size() > s1.size()) ? s2 : s1 };
    std::string s2l { (s2.size() > s1.size()) ? s1 : s2 };
    size_t N1 { s1l.size() };
    size_t N2 { s2l.size() };

    if (N1-N2 > 1) return false;
    bool foundDiff {false};

    for (size_t i {0}; i < N1; ++i) {
        size_t delta {0};
        if (N1!=N2 && foundDiff) delta = 1;
        if (s1l[i] != s2l[static_cast<size_t>(i-delta)]) {
            if (foundDiff) return false;
            else foundDiff = true;
        }
    }
    return true;
}
