/*
 * Solutions base class; interface for all challenges solved.
 * For each new solution added:
 *  1. make sure the interface is satisfied, including a good set of test cases returned by `testCases`
 *  2. add new solution to `Challenge` enum
 *  3. in both _main.cpp_ and _test.cpp_, update the switch statements in `getChallengeFromString` and `getSolverForChallenge`
 *  4. change `todaysChallenge` in _test.cpp_ to test that challenge's solution
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <string>
#include <vector>
#include <tuple>

enum class Challenge
{
    Unspecified,
    VowelSquare,
    PalindromeNumber,
    AddTwoNumbers,
    ClosestEnemy,
    LastStoneWeight,
    MAX_CHALENGE,
};

class Solution
{
protected:
    Solution(){}

    std::string rawInput;

public:
    virtual ~Solution(){};

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const = 0;
    virtual void setInput(const std::string input) { rawInput = input; }
    virtual std::string getSolution() const = 0;

protected:
    static std::vector<int> extractIntegers(const std::string &input, const std::string &caller = std::string());
    static std::vector<std::string> extractStrings(const std::string &input, const std::string &caller = std::string());
    static std::vector<std::vector<int>> extractIntMatrix(const std::string &input, const std::string &caller = std::string());
    static std::vector<std::vector<char>> extractCharMatrix(const std::string &input, const std::string &caller = std::string());
};

#endif // SOLUTION_H
