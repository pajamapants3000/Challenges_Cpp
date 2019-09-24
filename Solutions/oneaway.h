#ifndef ONEAWAY_H
#define ONEAWAY_H

#include "solution.h"

#include <string>
#include <vector>
#include <tuple>

using size_t = std::string::size_type;


class OneAway : public Solution
{
public:
    OneAway();
    explicit OneAway(std::string input);
    virtual ~OneAway() override;

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const override;
    virtual void setInput(const std::string input) override;
    virtual std::string getSolution() const override;

    virtual std::string key() override { return "oneaway"; }
    virtual std::string display() override { return "OneAway"; }

    static bool oneAway(const std::string s1, const std::string s2);

private:
    std::string m_s1;
    std::string m_s2;
};

#endif // ONEAWAY_H
