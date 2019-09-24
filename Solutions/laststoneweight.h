/*
1046. Last Stone Weight - https://leetcode.com/problems/last-stone-weight/
Easy

We have a collection of rocks, each rock has a positive integer weight.

Each turn, we choose the two heaviest rocks and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

    If x == y, both stones are totally destroyed;
    If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.

At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)



Example 1:

Input: [2,7,4,1,8,1]
Output: 1
Explanation:
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.



Note:

    1 <= stones.length <= 30
    1 <= stones[i] <= 1000

 */
#ifndef LASTSTONEWEIGHT_H
#define LASTSTONEWEIGHT_H

#include "solution.h"

#include <string>
#include <tuple>
#include <vector>

class LastStoneWeight : public Solution
{
public:
    LastStoneWeight();
    explicit LastStoneWeight(std::string input);
    virtual ~LastStoneWeight() override;

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const override;
    virtual void setInput(const std::string input) override;
    virtual std::string getSolution() const override;

    virtual std::string key() override { return "laststoneweight"; }
    virtual std::string display() override { return "LastStoneWeight"; }

private:
    std::vector<int> parseRockWeights(const std::string input);
    std::vector<int> smashRocks(std::vector<int> &weights) const;
    void sortRockWeights(std::vector<int>::iterator lo,
                         std::vector<int>::iterator hi) const;
    std::vector<int>::iterator partition(std::vector<int>::iterator lo,
                                         std::vector<int>::iterator hi) const;
    int pop(std::vector<int> &weights) const;
    void insert(std::vector<int> &weights, const int newWeight) const;
    bool comparator(int lo, int hi) const;
    std::vector<int>::size_type getRandomWeightIndex(std::vector<int>::size_type size) const;

    std::vector<int> rockWeights;
    bool useHomemadeSort;
};

#endif // LASTSTONEWEIGHT_H
