/*
StringRotation
Using only a single call to `isSubstring`, determine whether a string s1 is a rotation of another string s2.

Sample Test Cases

Input: ""
Output: true

Input: "erbottlewat bottlewater"
Output: true

Input: "iblyterr terrible"
Output: false

*/

/*
 * Assumptions:
 * None
*/

#ifndef STRINGROTATION_H
#define STRINGROTATION_H

#include <string>
#include <tuple>
#include <vector>

#include "solution.h"

class StringRotation : public Solution
{
public:
    StringRotation();
    explicit StringRotation(std::string input);
    virtual ~StringRotation() override;

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const override;
    virtual void setInput(const std::string input) override;
    virtual std::string getSolution() const override;

    static bool isRotation(const std::string s1, const std::string s2);

private:
    std::string m_s1;
    std::string m_s2;

    static bool isSubstring(const std::string s1, const std::string s2);

};

#endif // STRINGROTATION_H
