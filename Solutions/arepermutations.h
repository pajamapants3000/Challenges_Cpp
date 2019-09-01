/*
 * From Cracking the Coding Interview - Arrays and Strings
 *
 * can probably generalize this pretty easily to M words; would have to copy the counts mapping from the first word
 * could then determine whether all words are permutations of each other
 */

#ifndef AREPERMUTATIONS_H
#define AREPERMUTATIONS_H

#include "solution.h"

#include <string>

class ArePermutations : public Solution
{
public:
    ArePermutations();
    explicit ArePermutations(std::string input);
    virtual ~ArePermutations() override;

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const override;
    virtual void setInput(const std::string input) override;
    virtual std::string getSolution() const override;

    static bool arePermutations(const std::string s1, const std::string s2);
private:
    std::string m_s1;
    std::string m_s2;
};

#endif // AREPERMUTATIONS_H
