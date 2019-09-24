#ifndef URLIFY_H
#define URLIFY_H

#include "solution.h"

#include <string>
#include <vector>
#include <tuple>

using urlsize_t = std::string::size_type;

const std::string urlSpace { "%20" };

class Urlify : public Solution
{
public:
    Urlify();
    explicit Urlify(std::string input);
    virtual ~Urlify() override;

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const override;
    virtual void setInput(const std::string input) override;
    virtual std::string getSolution() const override;

    virtual std::string key() override { return "urlify"; }
    virtual std::string display() override { return "URLify"; }

    static void urlify(std::string &s, const urlsize_t N);

private:
    std::string m_s;
    std::size_t m_N;

    static urlsize_t countSpaces(const std::string s, const urlsize_t N);
    static void writeUrlSpace(std::string &s, const urlsize_t index);
};

#endif // URLIFY_H
