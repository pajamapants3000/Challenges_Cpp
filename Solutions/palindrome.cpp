#include "palindrome.h"

#include <string>
#include <tuple>
#include <vector>

#include "solutionio.h"
#include "../linkedlist.h"

Palindrome::Palindrome() :
    Solution(),
    m_head {nullptr}
{}

    Palindrome::Palindrome(std::string input) :
    Solution(),
    m_head {nullptr}
{
    setInput(input);
}

Palindrome::~Palindrome(){}

std::vector<std::tuple<std::string, std::string>> Palindrome::testCases() const
{
    return {{ "", "true"},
        { "t e s t i n g t e s t i n g", "false"},
        { "t e s t i n g n i t s e t", "true"},
        { "a b b a z a b b a z a b b a", "true"}};
};

void Palindrome::setInput(const std::string input)
{
    m_head = SllNode<char>::fromArray(extractArray<char>(input));
}

std::string Palindrome::getSolution() const
{
    return isPalindrome(m_head) ? "true" : "false";
}

bool Palindrome::isPalindrome(const SllNode<char>* head)
{
    size_t N { SllNode<char>::getLength(head) };
    if (N < 2) return true;
    return !!palindrome(head, N, N);
}

const SllNode<char>* Palindrome::palindrome(const SllNode<char>* head, const size_t N, const size_t NMax)
{
    if (NMax < 2) return head;

    const SllNode<char>* aft {nullptr};
    if (N == 1) aft = head;
    else if (N == 2) aft = head->next;
    else aft = palindrome(head->next, N-2, NMax);
    if (aft && aft->val == head->val) {
        if (N == NMax) return head;
        else return aft->next;
    } else {
        return nullptr;
    }
}

