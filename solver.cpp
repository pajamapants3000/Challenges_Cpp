#include "solver.h"

#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <locale>
#include <memory>

#include "Solutions/solution.h"       // abstract base class for all challenge solutions
#include "Solutions/solutionfactory.h"

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
    m_challenge = Solution::getChallengeFromString(challenge);
    if (m_challenge == Challenge::Unspecified) m_challenge = todaysChallenge;
}

void Solver::setChallenge(const Challenge challenge)
{
    m_challenge = challenge;
}

void Solver::run(const std::string input)
{
    m_solution = SolutionFactory::getSolution(input, m_challenge);
    std::cout << m_solution->getSolution();
}

void Solver::run_tests()
{
    if (m_challenge == Challenge::Unspecified) {
        for (int challenge { 1 };
                challenge != static_cast<int>(Challenge::MAX_CHALENGE);
                ++challenge) {
            std::shared_ptr<Solution> solution;
            try {
                solution = SolutionFactory::getSolution(static_cast<Challenge>(challenge));
                std::vector<testcase_t> tests = solution->testCases();
                run_test(solution, tests);
            } catch (const char* exStr) {
                std::cerr
                    << (solution ?
                        solution->display() :
                        "Solution")
                    << ": " << exStr << "\n";
            }
        }
    } else {
        m_solution = SolutionFactory::getSolution(m_challenge);
        m_tests = m_solution->testCases();

        run_test(m_solution, m_tests);
    }
}

void Solver::run_test(std::shared_ptr<Solution> solution, const std::vector<testcase_t> tests)
{
    int testCaseCount {0};
    int testCaseFailCount {0};

    testCaseHeader(solution->display());

    for (testcase_t testCase : tests) {
        if (!isTestCasePassing(solution, testCase)) {
            ++testCaseFailCount;
        }
        ++testCaseCount;
    }

    resultSummary(solution->display(), testCaseCount, testCaseFailCount);
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

void Solver::testCaseHeader(const std::string challenge) const
{
    std::cout << setConsolePurple << "*** " << challenge << " ***\n";
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

void Solver::resultSummary(const std::string challenge, const int count, const int fail) const
{
    std::cout << setConsolePurple
        << "> " << challenge << " Summary: "
        << count << " test cases; "
        << fail << " tests failed."
        << "\n\n" << unsetConsoleColor;
}
