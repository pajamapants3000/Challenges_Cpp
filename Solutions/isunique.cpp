#include "isunique.h"

#include <string>
#include <vector>
#include <tuple>

#include <cmath>
#include <climits>

#include "../sort.h"

IsUnique::IsUnique() :
    Solution(),
    m_s {},
    m_N {0},
    m_A {0}
{ }

IsUnique::IsUnique(std::string input) :
    Solution(),
    m_s {},
    m_N {0},
    m_A {0}
{
    setInput(input);
}

IsUnique::~IsUnique()
{
}

std::vector<std::tuple<std::string, std::string>> IsUnique::testCases() const
{
    return {{ "", "true"}, { "a", "true"}, { "aa", "false"},
        { "abc", "true"}, { "aba", "false"}, { "candidate", "false"},
        { "azbycxcwbv", "false"}};
}

void IsUnique::setInput(const std::string input)
{
    this->m_s = input;
    m_N = input.size();
    m_A = sizeOfAlphabet(sizeof(char));
}

std::string IsUnique::getSolution() const
{
    return isUnique(m_s.c_str(), m_N, m_A) ? "true" : "false";
}

std::size_t IsUnique::sizeOfAlphabet(std::size_t  sizeOfCharType) const
{
    double result {pow(2, CHAR_BIT)*sizeOfCharType};
    return static_cast<std::size_t>(result);
}

void IsUnique::copyArray(const char a[], char t[], size_t N) const
{
    for (size_t i {0}; i<N; ++i) {
        t[i] = a[i];
    }
}

bool IsUnique::isUnique(const char a[], std::size_t N, std::size_t A) const
{
    if (N>A) return false;
    if (N<2) return true;

    std::uint32_t found {0};    // requires A<=256
    for (size_t i {0}; i<N; ++i) {
        size_t c { static_cast<size_t>(a[i] - '\0') };  // we can trust that this difference is positive
        if (found & (1<<c)) return false;
        found |= (1<<c);
    }
    return true;
}

bool IsUnique::isUnique_Space(char a[], std::size_t N, std::size_t A) const
{
    if (N>A) return false;
    if (N<2) return true;

    Sort<char>::heapsort(a, N);

    for (size_t i {1}; i < N; ++i) {
        if (a[i-1] == a[i])
            return false;
    }
    return true;
}

