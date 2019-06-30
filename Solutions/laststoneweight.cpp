#include "laststoneweight.h"

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <tuple>
#include <vector>

LastStoneWeight::LastStoneWeight() :
    Solution(),
    rockWeights{},
    useHomemadeSort {false}
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

LastStoneWeight::LastStoneWeight(std::string input) :
    Solution(),
    rockWeights{},
    useHomemadeSort {false}
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    setInput(input);
}

LastStoneWeight::~LastStoneWeight(){}

std::string LastStoneWeight::getSolution() const
{
    std::vector<int> weights { rockWeights };
    while (weights.size() > 1) {
        weights = smashRocks(weights);
    }

    if (weights.size() == 1) {
        return std::to_string(weights.at(0));
    }

    return "0";
}

std::vector<std::tuple<std::string, std::string>> LastStoneWeight::testCases() const
{
    return {{ "", ""}, { "", ""}, { "", ""}};
}

void LastStoneWeight::setInput(std::string input)
{
    rawInput = input;
    rockWeights = parseRockWeights(input);
    //sortRockWeights(rockWeights);
    std::sort(rockWeights.begin(), rockWeights.end(), [](int p, int q) { return q < p; });
}

std::vector<int> LastStoneWeight::parseRockWeights(std::string input)
{
}

std::vector<int> LastStoneWeight::smashRocks(std::vector<int> &weights) const
{
}

void LastStoneWeight::sortRockWeights(std::vector<int>::iterator lo,
                                      std::vector<int>::iterator hi) const
{
    if (std::distance(lo, hi) <= 1) return;

    std::vector<int>::iterator p = partition(lo, hi);
    sortRockWeights(lo, p);
    sortRockWeights(p+1, hi);
}

std::vector<int>::iterator LastStoneWeight::partition(std::vector<int>::iterator lo,
                                                      std::vector<int>::iterator hi) const
{
    // we expect that lo is before hi
    std::vector<int>::difference_type size { std::distance(lo, hi) };
    if (size <= 0) {
        std::cerr << "LastStoneWeight.partition: An error occurred - called with invalid arguments: lo >= hi.\n";
        exit(1);
    }

    std::vector<int>::iterator p { lo };
    std::advance(p, getRandomWeightIndex(static_cast<std::vector<int>::size_type>(size)));

    std::vector<int>::iterator loScan { lo };
    std::vector<int>::iterator hiScan { hi };

    std::iter_swap(loScan, p);

    while (loScan < hiScan) {
        while (comparator(++loScan, p)) { if (loScan == hi) break; }
        while (comparator(p, --hiScan)) { if (hiScan == lo) break; }
        if (std::distance(loScan, hiScan) <= 0) break;
        std::iter_swap(loScan, hiScan);
    }

    std::iter_swap(p, hiScan);
    return hiScan;
}

bool LastStoneWeight::comparator(std::vector<int>::iterator lo,
                                 std::vector<int>::iterator hi) const
{
    return *lo > *hi;
}

std::vector<int>::size_type LastStoneWeight::getRandomWeightIndex(std::vector<int>::size_type size) const
{
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    return static_cast<std::vector<int>::size_type>(size * (std::rand() * fraction));
}
