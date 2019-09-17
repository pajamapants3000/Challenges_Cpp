/*
 * Solutions base class; interface for all challenges solved.
 * For each new solution added:
 *  1. make sure the interface is satisfied, including a good set of test cases returned by `testCases`
 *  2. add new solution to `Challenge` enum
 *  3. in both _main.cpp_ and _test.cpp_, update the switch statements in `getChallengeFromString` and `getSolverForChallenge`
 *  4. change `todaysChallenge` in _test.cpp_ to test that challenge's solution
 */

// Also including a lot of helper functions and templates - need tests!

#ifndef SOLUTION_H
#define SOLUTION_H

#include <string>
#include <vector>
#include <tuple>
#include <iostream>
#include <memory>

class Solution
{
public:
    virtual ~Solution();

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const = 0;
    virtual void setInput(const std::string input) = 0;
    virtual std::string getSolution() const = 0;
};

#endif // SOLUTION_H
