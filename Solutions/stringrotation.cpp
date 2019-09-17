#include "stringrotation.h"

#include <string>
#include <tuple>
#include <vector>

#include "solution.h"
#include "solutionio.h"

StringRotation::StringRotation() :
    Solution(),
    m_s1 {}, m_s2 {}
{}

  StringRotation::StringRotation(std::string input) :
  Solution(),
        m_s1 {}, m_s2 {}
{
        setInput(input);
}

StringRotation::~StringRotation(){}

std::vector<std::tuple<std::string, std::string>> StringRotation::testCases() const
{
    return {{ "", "true"},
        { "erbottlewat bottlewater", "true"},
        { "iblyterr terrible", "false"},
        { "aba bab", "false"}};
};

void StringRotation::setInput(const std::string input)
{
    const std::vector<std::string> in { extractArray<std::string>(input) };
    if (in.size() > 1) {
        m_s1 = in.at(0);
        m_s2 = in.at(1);
    }
}

std::string StringRotation::getSolution() const
{
    return isRotation(m_s1, m_s2) ? "true" : "false";
}

bool StringRotation::isRotation(const std::string possibleRotation, const std::string original)
{
    if (possibleRotation.size() != original.size()) return false;
    return isSubstring(possibleRotation, original+original);
}

bool StringRotation::isSubstring(const std::string possibleSubstring, const std::string original)
{
    return original.find(possibleSubstring) != std::string::npos;
}
