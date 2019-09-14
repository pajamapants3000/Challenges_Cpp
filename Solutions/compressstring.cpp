#include "compressstring.h"

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

CompressString::CompressString() :
    Solution(),
    m_s{}
{
}

CompressString::CompressString(std::string input) :
    Solution(),
    m_s{input}
{
}

CompressString::~CompressString()
{
}

std::vector<std::tuple<std::string, std::string>> CompressString::testCases() const
{
    return {{ "aaabcccccbbb", "a3b1c5b3"}, { "theonly", "theonly"}, { "a", "a"}, { "", "" }};
}

void CompressString::setInput(const std::string input)
{
    std::string in {input};
    m_s = in;
}

std::string CompressString::getSolution() const
{
    return compressString(m_s);
}

std::string CompressString::compressString(const std::string s)
{
    std::string compressed { std::string(s.size(), 0) };
    size_t counter {0};
    size_t compressedLength {0};
    char currentChar {0};
    for (size_t i {0}; i <= s.size(); ++i) {
        if (i == s.size() || s.at(i) != currentChar) {
            if (currentChar) {  // skips i==1, when currentChar=='\0'
                size_t growth {addCharCount(compressed, compressedLength, s.size(), currentChar, counter)};
                if (growth == 0) return s;
                compressedLength += growth;
            }
            if (i != s.size()) {
                counter = 1;
                currentChar = s.at(i);
            }
        } else {
            ++counter;
        }
    }

    compressed.resize(compressedLength);
    return compressed;
}

size_t CompressString::addCharCount(std::string &s, size_t currentSize, size_t maxSize, char c, size_t count)
{
    if (currentSize >= maxSize) return 0;
    std::string toAdd { std::string(1, c) };
    toAdd.append( std::to_string(count) );
    size_t free { static_cast<size_t>(maxSize-currentSize) };
    if (toAdd.size() > free) return 0;

    for (size_t i {0}; i < toAdd.size(); ++i) {
        //s[currentSize+i] = toAdd.at(i);
        s.at(currentSize+i) = toAdd.at(i);
    }

    return toAdd.size();
}
