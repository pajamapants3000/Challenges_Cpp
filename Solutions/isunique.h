/*
 * From Cracking the Coding Interview - Arrays and Strings
 */

#ifndef ISUNIQUE_H
#define ISUNIQUE_H

#include "solution.h"

#include <string>
#include <vector>
#include <tuple>

class IsUnique : public Solution
{
public:
    IsUnique();
    explicit IsUnique(std::string input);
    virtual ~IsUnique() override;

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const override;
    virtual void setInput(const std::string input) override;
    virtual std::string getSolution() const override;

    bool isUnique(const char s[], std::size_t N, std::size_t A) const;
    bool isUnique_Space(char s[], std::size_t N, std::size_t A) const;
    std::size_t sizeOfAlphabet(std::size_t sizeOfCharType) const;

private:
    std::string m_s;
    std::size_t m_N;
    std::size_t m_A;

    void copyArray(const char s[], char t[], size_t N) const;
};

#endif // ISUNIQUE_H
