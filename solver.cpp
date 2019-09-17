#include "solver.h"

#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <locale>
#include <memory>

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
#include "Solutions/compressstring.h"
#include "Solutions/rotatematrix.h"
#include "Solutions/zeromatrix.h"
#include "Solutions/stringrotation.h"
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
    m_solution = solutionFactory(input, m_challenge);
    std::cout << m_solution->getSolution();
}

void Solver::run_tests()
{
    if (m_challenge == Challenge::Unspecified) {
        for (int challenge { 1 };
                challenge != static_cast<int>(Challenge::MAX_CHALENGE);
                ++challenge) {
            try {
                std::shared_ptr<Solution> solution = solutionFactory(static_cast<Challenge>(challenge));
                std::vector<testcase_t> tests = solution->testCases();
                run_test(static_cast<Challenge>(challenge), solution, tests);
            } catch (const char* exStr) {
                std::cerr << getStringFromChallenge(static_cast<Challenge>(challenge)) << ": " << exStr << "\n";
            }
        }
    } else {
        m_solution = solutionFactory(m_challenge);
        m_tests = m_solution->testCases();

        run_test(m_challenge, m_solution, m_tests);
    }
}

void Solver::run_test(const Challenge challenge, std::shared_ptr<Solution> solution, const std::vector<testcase_t> tests)
{
    int testCaseCount {0};
    int testCaseFailCount {0};

    testCaseHeader(challenge);

    for (testcase_t testCase : tests) {
        if (!isTestCasePassing(solution, testCase)) {
            ++testCaseFailCount;
        }
        ++testCaseCount;
    }

    resultSummary(challenge, testCaseCount, testCaseFailCount);
}

std::string Solver::getStringFromChallenge(const Challenge challenge) const
{
    if (challenge == Challenge::VowelSquare) {
        return "VowelSquare";
    } else if (challenge == Challenge::PalindromeNumber) {
        return "PalindromeNumber";
    } else if (challenge == Challenge::AddTwoNumbers) {
        return "AddTwoNumbers";
    } else if (challenge == Challenge::ClosestEnemy) {
        return "ClosestEnemy";
    } else if (challenge == Challenge::LastStoneWeight) {
        return "LastStoneWeight";
    } else if (challenge == Challenge::StringSort) {
        return "StringSort";
    } else if (challenge == Challenge::IsUnique) {
        return "IsUnique";
    } else if (challenge == Challenge::ArePermutations) {
        return "ArePermutations";
    } else if (challenge == Challenge::Urlify) {
        return "Urlify";
    } else if (challenge == Challenge::PalindromePermutation) {
        return "PalindromePermutation";
    } else if (challenge == Challenge::OneAway) {
        return "OneAway";
    } else if (challenge == Challenge::CompressString) {
        return "CompressString";
    } else if (challenge == Challenge::RotateMatrix) {
        return "RotateMatrix";
    } else if (challenge == Challenge::ZeroMatrix) {
        return "ZeroMatrix";
    } else if (challenge == Challenge::StringRotation) {
        return "StringRotation";
    } else {
        throw "No challenge specified.";
    }
}

Challenge Solver::getChallengeFromString(const std::string input)
{
    std::locale loc;
    for (std::string::size_type i=0; i<input.length(); ++i)
        std::tolower(input[i],loc);

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
    } else if (input == "compressstring") {
        return Challenge::CompressString;
    } else if (input == "rotatematrix") {
        return Challenge::RotateMatrix;
    } else if (input == "zeromatrix") {
        return Challenge::ZeroMatrix;
    } else if (input == "stringrotation") {
        return Challenge::StringRotation;
    } else {
        return Challenge::Unspecified;
    }
}

std::shared_ptr<Solution> Solver::solutionFactory(const Challenge challenge)
{
    Challenge challenge_local { challenge == Challenge::Unspecified ? todaysChallenge : challenge };

    switch (challenge_local)
    {
    case Challenge::VowelSquare:
        return std::shared_ptr<Solution>(new VowelSquare());
    case Challenge::PalindromeNumber:
        return std::shared_ptr<Solution>(new PalindromeNumber());
    case Challenge::AddTwoNumbers:
        return std::shared_ptr<Solution>(new AddTwoNumbers());
    case Challenge::ClosestEnemy:
        return std::shared_ptr<Solution>(new ClosestEnemy());
    case Challenge::LastStoneWeight:
        return std::shared_ptr<Solution>(new LastStoneWeight());
    case Challenge::StringSort:
        return std::shared_ptr<Solution>(new StringSort());
    case Challenge::IsUnique:
        return std::shared_ptr<Solution>(new IsUnique());
    case Challenge::ArePermutations:
        return std::shared_ptr<Solution>(new ArePermutations());
    case Challenge::Urlify:
        return std::shared_ptr<Solution>(new Urlify());
    case Challenge::PalindromePermutation:
        return std::shared_ptr<Solution>(new PalindromePermutation());
    case Challenge::OneAway:
        return std::shared_ptr<Solution>(new OneAway());
    case Challenge::CompressString:
        return std::shared_ptr<Solution>(new CompressString());
    case Challenge::RotateMatrix:
        return std::shared_ptr<Solution>(new RotateMatrix());
    case Challenge::ZeroMatrix:
        return std::shared_ptr<Solution>(new ZeroMatrix());
    case Challenge::StringRotation:
        return std::shared_ptr<Solution>(new StringRotation());
    default:
        return nullptr;
    }
}

std::shared_ptr<Solution> Solver::solutionFactory(const std::string input, const Challenge challenge)
{
    Challenge challenge_local { challenge == Challenge::Unspecified ? todaysChallenge : challenge };

    switch (challenge_local)
    {
    case Challenge::VowelSquare:
        return std::shared_ptr<Solution>(new VowelSquare(input));
    case Challenge::PalindromeNumber:
        return std::shared_ptr<Solution>(new PalindromeNumber(input));
    case Challenge::AddTwoNumbers:
        return std::shared_ptr<Solution>(new AddTwoNumbers(input));
    case Challenge::ClosestEnemy:
        return std::shared_ptr<Solution>(new ClosestEnemy(input));
    case Challenge::LastStoneWeight:
        return std::shared_ptr<Solution>(new LastStoneWeight(input));
    case Challenge::StringSort:
        return std::shared_ptr<Solution>(new StringSort(input));
    case Challenge::IsUnique:
        return std::shared_ptr<Solution>(new IsUnique(input));
    case Challenge::ArePermutations:
        return std::shared_ptr<Solution>(new ArePermutations(input));
    case Challenge::Urlify:
        return std::shared_ptr<Solution>(new Urlify(input));
    case Challenge::PalindromePermutation:
        return std::shared_ptr<Solution>(new PalindromePermutation(input));
    case Challenge::OneAway:
        return std::shared_ptr<Solution>(new OneAway(input));
    case Challenge::CompressString:
        return std::shared_ptr<Solution>(new CompressString(input));
    case Challenge::RotateMatrix:
        return std::shared_ptr<Solution>(new RotateMatrix(input));
    case Challenge::ZeroMatrix:
        return std::shared_ptr<Solution>(new ZeroMatrix(input));
    case Challenge::StringRotation:
        return std::shared_ptr<Solution>(new StringRotation(input));
    default:
        return nullptr;
    }
}

bool Solver::isTestCasePassing(std::shared_ptr<Solution> solver, const std::tuple<std::string, std::string> testCase) const
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

void Solver::testCaseHeader(const Challenge challenge) const
{
    std::cout << setConsolePurple << "*** " << getStringFromChallenge(challenge) << " ***\n";
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

void Solver::resultSummary(const Challenge challenge, const int count, const int fail) const
{
    std::cout << setConsolePurple
        << "> " << getStringFromChallenge(challenge) << " Summary: "
        << count << " test cases; "
        << fail << " tests failed."
        << "\n\n" << unsetConsoleColor;
}
