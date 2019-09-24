#ifndef STRINGSORT_H
#define STRINGSORT_H

#include "solution.h"

#include <vector>

#include "../sort.h"

class StringSort : public Solution
{
public:
    StringSort();
    explicit StringSort(std::string input);
    virtual ~StringSort() override;

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const override;
    virtual void setInput(const std::string input) override;
    virtual std::string getSolution() const override;

    virtual std::string key() override { return "stringsort"; }
    virtual std::string display() override { return "StringSort"; }

private:
    Sort<char>* m_sorter;

};

#endif // STRINGSORT_H
