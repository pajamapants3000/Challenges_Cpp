#ifndef SOLVER_H
#define SOLVER_H

#include "Solutions/solution.h"

#include <string>
#include <tuple>
#include <memory>

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
    StringRotation,
    MAX_CHALENGE,
};

/* Specify which challege solution to test here */
static const Challenge todaysChallenge { Challenge::Unspecified };
/* ******************************************** */

/* Additional Constants */
constexpr int inputMaxChar { 65536 };
constexpr char setConsoleGreen[] { "\033[0;32m" };
constexpr char setConsoleRed[] { "\033[0;31m" };
constexpr char setConsolePurple[] { "\033[0;35m" };
constexpr char unsetConsoleColor[] { "\033[0m" };
/* ********* */

typedef std::tuple<std::string, std::string> testcase_t;

class Solver
{

public:
    explicit Solver(const Challenge challenge = Challenge::Unspecified);
    explicit Solver(const std::string challenge);

    void run(const std::string input);
    void run_test(const Challenge challenge, std::shared_ptr<Solution> solution, const std::vector<testcase_t> tests);
    void run_tests();

    static std::shared_ptr<Solution> solutionFactory(const Challenge challenge = todaysChallenge);
    static std::shared_ptr<Solution> solutionFactory(const std::string input, const Challenge challenge = todaysChallenge);
    std::string getStringFromChallenge(const Challenge challenge) const;
    static Challenge getChallengeFromString(const std::string challenge);

    void setChallenge(const Challenge challenge);
private:
    Challenge m_challenge;
    std::shared_ptr<Solution> m_solution;
    std::string m_input;
    std::vector<testcase_t> m_tests;

    void testCaseHeader(const Challenge challenge) const;
    bool isTestCasePassing(std::shared_ptr<Solution> solution, const testcase_t testCase) const;
    void testCasePass(const std::string in, const std::string out) const;
    void testCaseFail(const std::string in, const std::string out, const std::string expected) const;
    void resultSummary(const Challenge challenge, const int count, const int fail) const;
};

#endif // SOLVER_H
