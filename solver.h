#ifndef SOLVER_H
#define SOLVER_H

#include "Solutions/solution.h"

#include <string>
#include <tuple>

/* Specify which challege solution to test here */
static const Challenge todaysChallenge { Challenge::VowelSquare };
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
    void run_tests();

    static Solution* getSolverForChallenge(const Challenge challenge = todaysChallenge);
    static Solution* getSolverForChallenge(const std::string input, const Challenge challenge = todaysChallenge);
    static Challenge getChallengeFromString(const std::string challenge);

    void setChallenge(const Challenge challenge);
private:
    Challenge m_challenge;
    Solution* m_solution;
    std::string m_input;
    std::vector<testcase_t> m_tests;

    bool isTestCasePassing(Solution *solution, const std::tuple<std::string, std::string> testCase) const;
    void testCasePass(const std::string in, const std::string out) const;
    void testCaseFail(const std::string in, const std::string out, const std::string expected) const;
    void ResultSummary(const int count, const int fail) const;
};

#endif // SOLVER_H
