#include "laststoneweight.h"

#include <string>
#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>    // sort
#include <cstdlib>      // rand, srand
#include <ctime>        // get time for srand seed value

LastStoneWeight::LastStoneWeight() :
    Solution(),
    rockWeights{},
    useHomemadeSort {true}
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

LastStoneWeight::LastStoneWeight(std::string input) :
    Solution(),
    rockWeights{},
    useHomemadeSort {true}
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    setInput(input);
}

LastStoneWeight::~LastStoneWeight(){}

std::vector<std::tuple<std::string, std::string>> LastStoneWeight::testCases() const
{
    return {{ "2 7 4 1 8 1", "1"}, { "24 182 17 2 33 13 98 11", "6"}, { "421 873 37 122 293", "0"}};
}

void LastStoneWeight::setInput(const std::string input)
{
    rockWeights = parseRockWeights(input);
    if (useHomemadeSort) {
        sortRockWeights(rockWeights.begin(), rockWeights.end());
    } else {
        std::sort(rockWeights.begin(), rockWeights.end(), [](int p, int q) { return p < q; });
    }
}

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

std::vector<int> LastStoneWeight::parseRockWeights(const std::string input)
{
    std::vector<int> result {};
    std::string::size_type pos {0};
    std::string::size_type posNext {0};
    int num {0};

    try {
        while (pos != input.length()) {
            num = std::stoi(input.substr(pos), &posNext, 0);
            pos += posNext;
            result.push_back(num);
        }
    } catch (std::invalid_argument &ia) {
        std::cerr << "LastStoneWeight::parseRockWeights - invalid input.\n" << ia.what();
        exit(1);
    } catch (std::out_of_range &oor) {
        std::cerr << "LastStoneWeight::parseRockWeights - out of range.\n" << oor.what();
        exit(1);
    } catch (...) {
        std::cerr << "LastStoneWeight::parseRockWeights - unknown exception.\n";
        exit(1);
    }

    return result;
}

std::vector<int> LastStoneWeight::smashRocks(std::vector<int> &weights) const
{
    // weights must be sorted ascending!
    int m1 { pop(weights) };
    int m2 { pop(weights) };
    int smash { m1 - m2 };
    if (smash != 0) {
        insert(weights, smash);
    }

    return weights;
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

    std::iter_swap(lo, p);
    p = lo;

    while (loScan < hiScan) {
        while (comparator(*(++loScan), *p)) { if (loScan == hi) break; }
        while (comparator(*p, *(--hiScan))) { if (hiScan == lo) break; }
        if (std::distance(loScan, hiScan) <= 0) break;
        std::iter_swap(loScan, hiScan);
    }

    std::iter_swap(p, hiScan);
    return hiScan;
}

int LastStoneWeight::pop(std::vector<int> &weights) const
{
    int result { *(weights.end() - 1) };
    weights.pop_back();
    return result;
}

void LastStoneWeight::insert(std::vector<int> &weights, const int newWeight) const
{
    std::vector<int>::const_iterator citer { weights.cbegin() };
    std::vector<int>::const_iterator last { weights.cend() };
    citer = std::find_if(citer, last, [&](const int wt){ return comparator(newWeight, wt); } );
    weights.insert(citer, newWeight);
}

// ascending order
bool LastStoneWeight::comparator(const int lo, const int hi) const
{
    return lo < hi;
}

std::vector<int>::size_type LastStoneWeight::getRandomWeightIndex(std::vector<int>::size_type size) const
{
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    return static_cast<std::vector<int>::size_type>(size * (std::rand() * fraction));
}
