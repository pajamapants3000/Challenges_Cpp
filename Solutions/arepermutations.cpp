#include "arepermutations.h"

#include <vector>
#include <string>
#include <sstream>
#include <map>

using char_t = std::string::value_type;
using map_t = std::map<char_t, size_t>;

ArePermutations::ArePermutations() :
    Solution(),
    m_s1 {},
    m_s2 {}
{}

ArePermutations::ArePermutations(std::string input) :
    Solution(),
    m_s1 {},
    m_s2 {}
{
    setInput(input);
}

ArePermutations::~ArePermutations() {}

std::vector<std::tuple<std::string, std::string>> ArePermutations::testCases() const
{
    return { { "abcdefg gfedcba", "true" }, { "a a", "true" }, { "", "true" },
        { "a", "false" }, { "a b", "false" }, { "abcdefgazdz gfaeddzzcba", "true" } };
}

void ArePermutations::setInput(const std::string input)
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

std::string ArePermutations::getSolution() const
{
    return arePermutations(m_s1, m_s2) ? "true" : "false";
}

bool ArePermutations::arePermutations(const std::string s1, const std::string s2)
{
    if (s1.size() != s2.size()) return false;
    if (s1.size() == 0) return true;

    map_t counts;
    for (char_t c : s1) {
        map_t::iterator iter { counts.find(c) };
        if (iter != counts.end()) {
            //++((*iter).second); // might be faster
            ++counts[c];
        } else {
            counts[c] = 1;
        }
    }
    for (char_t c : s2) {
        map_t::iterator iter { counts.find(c) };
        if (iter != counts.end()) {
            //--((*iter).second); // might be faster
            --counts[c];
        } else {
            return false;
        }
    }
    return true;
}
