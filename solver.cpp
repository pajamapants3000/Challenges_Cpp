#include "solver.h"

#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <locale>

#include "Solutions/solution.h"       // abstract base class for all challenge solutions
/* Challenge solutions */
#include "Solutions/vowelsquare.h"
#include "Solutions/palindromenumber.h"
#include "Solutions/addtwonumbers.h"
#include "Solutions/closestenemy.h"
#include "Solutions/laststoneweight.h"
#include "Solutions/stringsort.h"
#include "Solutions/isunique.h"
#include "Solutions/arepermutations.h"
#include "Solutions/urlify.h"
#include "Solutions/palindromepermutation.h"
#include "Solutions/oneaway.h"
/* ******************* */

Solver::Solver(const Challenge challenge) :
    m_challenge { challenge },
    m_solution {nullptr},
    m_tests {}
{
    if (challenge == Challenge::Unspecified) m_challenge = todaysChallenge;
}

Solver::Solver(const std::string challenge) :
    m_challenge {},
    m_solution {nullptr},
    m_tests {}
{
    m_challenge = getChallengeFromString(challenge);
    if (m_challenge == Challenge::Unspecified) m_challenge = todaysChallenge;
}

void Solver::setChallenge(const Challenge challenge)
{
    m_challenge = challenge;
}

void Solver::run(const std::string input)
{
    m_solution = getSolverForChallenge(input, m_challenge);
    std::cout << m_solution->getSolution();
}

void Solver::run_tests()
{
    m_solution = getSolverForChallenge(m_challenge);
    m_tests = m_solution->testCases();

    int testCaseCount {0};
    int testCaseFailCount {0};

    for (testcase_t testCase : m_tests) {
        if (!isTestCasePassing(m_solution, testCase)) {
            ++testCaseFailCount;
        }
        ++testCaseCount;
    }

    ResultSummary(testCaseCount, testCaseFailCount);
}

Challenge Solver::getChallengeFromString(const std::string input)
{
    std::locale loc;
    for (std::string::size_type i=0; i<input.length(); ++i)
    std::cout << std::tolower(input[i],loc);

    if (input == "vowelsquare") {
        return Challenge::VowelSquare;
    } else if (input == "palindromenumber") {
        return Challenge::PalindromeNumber;
    } else if (input == "addtwonumbers") {
        return Challenge::AddTwoNumbers;
    } else if (input == "closestenemy") {
        return Challenge::ClosestEnemy;
    } else if (input == "laststoneweight") {
        return Challenge::LastStoneWeight;
    } else if (input == "stringsort") {
        return Challenge::StringSort;
    } else if (input == "isunique") {
        return Challenge::IsUnique;
    } else if (input == "arepermutations") {
        return Challenge::ArePermutations;
    } else if (input == "urlify") {
        return Challenge::Urlify;
    } else if (input == "palindromepermutation") {
        return Challenge::PalindromePermutation;
    } else if (input == "oneaway") {
        return Challenge::OneAway;
    } else {
        return Challenge::Unspecified;
    }
}

Solution* Solver::getSolverForChallenge(const Challenge challenge)
{
    Challenge challenge_local { challenge == Challenge::Unspecified ? todaysChallenge : challenge };

    switch (challenge_local)
    {
    case Challenge::VowelSquare:
        return new VowelSquare();
    case Challenge::PalindromeNumber:
        return new PalindromeNumber();
    case Challenge::AddTwoNumbers:
        return new AddTwoNumbers();
    case Challenge::ClosestEnemy:
        return new ClosestEnemy();
    case Challenge::LastStoneWeight:
        return new LastStoneWeight();
    case Challenge::StringSort:
        return new StringSort();
    case Challenge::IsUnique:
        return new IsUnique();
    case Challenge::ArePermutations:
        return new ArePermutations();
    case Challenge::Urlify:
        return new Urlify();
    case Challenge::PalindromePermutation:
        return new PalindromePermutation();
    case Challenge::OneAway:
        return new OneAway();
    default:
        return nullptr;
    }
}

Solution* Solver::getSolverForChallenge(const std::string input, const Challenge challenge)
{
    Challenge challenge_local { challenge == Challenge::Unspecified ? todaysChallenge : challenge };

    switch (challenge_local)
    {
    case Challenge::VowelSquare:
        return new VowelSquare(input);
    case Challenge::PalindromeNumber:
        return new PalindromeNumber(input);
    case Challenge::AddTwoNumbers:
        return new AddTwoNumbers(input);
    case Challenge::ClosestEnemy:
        return new ClosestEnemy(input);
    case Challenge::LastStoneWeight:
        return new LastStoneWeight(input);
    case Challenge::StringSort:
        return new StringSort(input);
    case Challenge::IsUnique:
        return new IsUnique(input);
    case Challenge::ArePermutations:
        return new ArePermutations(input);
    case Challenge::Urlify:
        return new Urlify(input);
    case Challenge::PalindromePermutation:
        return new PalindromePermutation(input);
    case Challenge::OneAway:
        return new OneAway(input);
    default:
        return nullptr;
    }
}

bool Solver::isTestCasePassing(Solution *solver, const std::tuple<std::string, std::string> testCase) const
{
        std::string in { std::get<0>(testCase) };
        std::string expected { std::get<1>(testCase) };

        solver->setInput(in);
        std::string out = solver->getSolution();

        if (out == expected) {
            testCasePass(in, out);
            return true;
        }

        testCaseFail(in, out, expected);
        return false;
}

void Solver::testCasePass(const std::string in, const std::string out) const
{
    std::cout << setConsoleGreen << "PASS: " << unsetConsoleColor << in << " -> " << out << "\n";
}

void Solver::testCaseFail(const std::string in, const std::string out, const std::string expected) const
{
    std::cout << setConsoleRed << "FAIL: " << unsetConsoleColor << in << "\n";
    std::cout << "    expected: " << expected << "\n";
    std::cout << "    actual: " << out << "\n";
}

void Solver::ResultSummary(const int count, const int fail) const
{
    std::cout << setConsolePurple << "Summary: " << count << " test cases; " << fail << " tests failed.\n" << unsetConsoleColor;
}
