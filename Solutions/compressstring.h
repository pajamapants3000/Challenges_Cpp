#ifndef COMPRESSSTRING_H
#define COMPRESSSTRING_H

#include "solution.h"

#include <string>
#include <vector>

using size_t = std::string::size_type;

class CompressString : public Solution
{
public:
    CompressString();
    explicit CompressString(std::string input);
    virtual ~CompressString() override;

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const override;
    virtual void setInput(const std::string input) override;
    virtual std::string getSolution() const override;

    virtual std::string key() override { return "compressstring"; }
    virtual std::string display() override { return "CompressString"; }

    static std::string compressString(const std::string s);

private:
    std::string m_s;

    static size_t addCharCount(std::string &s, size_t currentSize,
                               size_t maxSize, char c, size_t count);

};

#endif // COMPRESSSTRING_H
