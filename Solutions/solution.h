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
    StringSort,
    VowelSquare,
    PalindromeNumber,
    AddTwoNumbers,
    ClosestEnemy,
    LastStoneWeight,
    IsUnique,
    ArePermutations,
    Urlify,
    PalindromePermutation,
    OneAway,
    CompressString,
    RotateMatrix,
    MAX_CHALENGE,
};

class Solution
{
protected:
    Solution();

    std::string rawInput;

public:
    virtual ~Solution();

    virtual std::vector<std::tuple<std::string, std::string>> testCases() const = 0;
    virtual void setInput(const std::string input) { rawInput = input; }
    virtual std::string getSolution() const = 0;

protected:
    static std::vector<int> extractIntegers(const std::string &input, const std::string &caller = std::string());
    static std::vector<std::string> extractStrings(const std::string &input, const std::string &caller = std::string());
    static std::vector<std::vector<char>> extractCharMatrix(const std::string &input, const std::string &caller = std::string());

    template <typename T>
    static std::vector<std::vector<T>> extractIntMatrix(const std::string &input, const std::string &caller);
    template <typename T>
    static void extractIntMatrix(T** &M, std::size_t &N, const std::string &input, const std::string &caller = std::string());

    template <typename T>
    static void extractArray(T* &a, std::size_t &N, const std::string &input, const std::string &caller = std::string());
    template <typename T>
    static void extractArray(T** &a, std::size_t &N, const std::string &input, const std::string &caller = std::string());
    template <typename T>
    static std::vector<T> extractArray(const std::string &input, const std::string &caller = std::string());
    template <typename T>
    static std::vector<std::vector<T>> extractArray(const std::string &input, const std::string &caller = std::string());

    template <typename T>
    static std::string arrayToString(T* a, const std::size_t N);
    template <typename T>
    static std::string arrayToString(T** a, const std::size_t N1, const std::size_t N2);
    template <typename T>
    static std::string arrayToString(std::vector<T> a);
    template <typename T>
    static std::string arrayToString(std::vector<std::vector<T>> a);

    template <typename T>
    static std::vector<std::vector<T>> makeCopy(const std::vector<std::vector<T>>& toCopy);
    template <typename T>
    static std::vector<T> makeCopy(const std::vector<T>& toCopy);
};

#include "solution.inl"

#endif // SOLUTION_H
