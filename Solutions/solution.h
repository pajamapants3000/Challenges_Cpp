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
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <iostream>
#include <stdexcept>
#include <cstdio>

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
    ZeroMatrix,
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
};

template <typename T>
T stringToAny(const std::string &/*input*/, std::string::size_type &/*position*/)
{
    throw "stringToAny not implemented for type.";
}

template <typename T>
const std::vector<T> extractArray(const std::string &input, const std::string &caller = "Solution")
{
    std::vector<T> result {};
    T next;
    std::string::size_type pos {0};

    try {
        while (pos < input.size()) {
            std::string::size_type nextpos {0};
            next = stringToAny<T>(input.substr(pos), nextpos);
            pos += nextpos+1;
            result.push_back(next);
        }
    } catch (const std::invalid_argument& ia) {
        std::cerr << caller << ": Invalid input: " << ia.what() << "\n";
        exit(1);
    } catch (const std::out_of_range& oor) {
        std::cerr << caller << ": Input out of range: " << oor.what() << "\n";
        exit(1);
    } catch (const std::exception& ex) {
        std::cerr << caller << ": " << ex.what() << "\n";
        exit(1);
    } catch (...) {
        std::cerr << caller << ": Failed to parse from input.\n";
        exit(1);
    }
    return result;
}

template <typename T>
std::vector<std::vector<T>> extractMatrix(const std::string &input, const std::string &caller = "Solution")
{
    std::vector<std::vector<T>> result {};
    std::string::size_type pos {0};

    while (pos < input.size()) {
        std::string::size_type nextPos {input.find_first_of(",", pos)};
        result.push_back(extractArray<T>(input.substr(pos, nextPos-pos), caller));
        if (nextPos == std::string::npos) break;
        pos = nextPos+1;
    }
    return result;
}

template <typename T>
void extractArray(T* &a, std::size_t &N, const std::string &input, const std::string &caller = "Solution")
{
    std::vector<T> resultVector { extractArray<T>(input, caller) };
    N = resultVector.size();
    a = new T[N];
    for (typename std::vector<T>::size_type i {0}; i < N; ++i) {
        a[i] = resultVector.at(i);
    }
}

template <typename T>
void extractMatrix(T** &a, std::size_t &N, const std::string &input, const std::string &caller = "Solution")
{
    std::vector<std::vector<T>> resultVector { extractMatrix<T>(input, caller) };
    N = resultVector.size();
    a = new T*[N];
    for (typename std::vector<std::vector<T>>::size_type i {0}; i < N; ++i) {
        a[i] = new T[N];
        for (typename std::vector<T>::size_type j {0}; j < N; ++j) {
            a[i][j] = resultVector.at(i).at(j);
        }
    }
}

template <typename T>
std::string arrayToString(T* a, const std::size_t N)
{
    std::string result {};

    for (std::size_t i {0}; i < N; ++i) {
        result.append(std::to_string(a[i]));
        if (i != N-1) {
            result.append(" ");
        }
    }
    return result;
}

template <typename T>
std::string matrixToString(T** a, const std::size_t N1, const std::size_t N2)
{
    std::string result {};

    for (std::size_t i {0}; i < N2; ++i) {
        std::string next {arrayToString<T>(a[i], N1)};
        result.append(next);
        if (i != N2-1) {
            result.append(", ");
        }
    }
    return result;
}

template <typename T>
std::string arrayToString(std::vector<T> a)
{
    std::string result {};

    for (std::size_t i {0}; i < a.size(); ++i) {
        result.append(std::to_string(a.at(i)));
        if (i != (a.size()-1)) {
            result.append(" ");
        }
    }
    return result;
}

template <typename T>
std::string matrixToString(std::vector<std::vector<T>> a)
{
    std::string result {};

    for (std::size_t i {0}; i < a.size(); ++i) {
        std::string next {arrayToString<T>(a.at(i))};
        result.append(next);
        if (i != (a.size()-1)) {
            result.append(", ");
        }
    }
    return result;
}

template <typename T>
std::vector<T> arrayCopy(const std::vector<T>& toCopy)
{
    std::vector<T> result {};
    for (T element : toCopy) {
        result.push_back(element);
    }
    return result;
}

template <typename T>
std::vector<std::vector<T>> matrixCopy(const std::vector<std::vector<T>>& toCopy)
{
    std::vector<std::vector<T>> result {};
    for (std::vector<T> row : toCopy) {
        result.push_back(arrayCopy(row));
    }
    return result;
}

#endif // SOLUTION_H
