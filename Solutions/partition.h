/*
Partition
Partition a singly-linked list about a partition value X

Sample Test Cases

Input: 5, 3 5 8 5 10 2 1

Output: 3 1 2 10 5 5 8 (from text. I actually expect 3 2 1 5 8 5 10, though it need not be exact)

*/

/*
 * Assumptions:
 * Data type int
*/

#ifndef PARTITION_H
#define PARTITION_H

#include <string>
#include <tuple>
#include <vector>

#include "solution.h"

#include "../linkedlist.h"

class Partition : public Solution
{
public:
    Partition();
    explicit Partition(std::string input);
    virtual ~Partition() override;

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const override;
    virtual void setInput(const std::string input) override;
    virtual std::string getSolution() const override;

    virtual std::string key() { return "partition"; }
    virtual std::string display() { return "Partition"; }

    static void partition(SllNode<int>* in, int part);

private:
    SllNode<int>* m_list;
    int m_part;
};

#endif // PARTITION_H

