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
    // set input; solution.h provides methods like extractArray to assist
}

std::string RemoveDups::getSolution() const
{
    // copy members if necessary to preserve constness; solution.h provides methods like makeCopy to assist
    return /*convert_result_to_string(removedups(args))*/ "";
}

DllNode<char>* removedups(DllNode<char>* pHead)
{
    // solution
}

