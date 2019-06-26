#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <locale>

#include "solution.h"       // abstract base class for all challenge solutions
/* Challenge solutions */
#include "vowelsquare.h"
/* ******************* */

/* Specify which challege solution to test here */
static const Challenge todaysChallenge { Challenge::VowelSquare };
/* ******************************************** */

/* Additional Constants */
constexpr char setConsoleGreen[] { "\033[0;32m" };
constexpr char setConsoleRed[] { "\033[0;31m" };
constexpr char setConsolePurple[] { "\033[0;35m" };
constexpr char unsetConsoleColor[] { "\033[0m" };
/* ********* */


/* Forward Declarations */
bool isTestCasePassing(Solution *solution, std::tuple<std::string, std::string> testCase);
void testCasePass(std::string in, std::string out);
void testCaseFail(std::string in, std::string out, std::string expected);
void ResultSummary(int count, int fail);
Challenge getChallengeFromString(std::string challenge);
Solution* getSolverForChallenge(Challenge challenge = todaysChallenge);
/* ******************** */

int main(int argc, char *argv[])
{
    int testCaseCount {0};
    int testCaseFailCount {0};

    Challenge challenge { todaysChallenge };
    if (argc > 1) {
        challenge = getChallengeFromString(argv[1]);
    }

    Solution *solver { getSolverForChallenge(challenge) };
    std::vector<std::tuple<std::string, std::string>> testCases = solver->testCases();

    for (std::tuple<std::string, std::string> testCase : testCases) {
        if (!isTestCasePassing(solver, testCase)) {
            ++testCaseFailCount;
        }
        ++testCaseCount;
    }

    ResultSummary(testCaseCount, testCaseFailCount);
    return 0;
}

Challenge getChallengeFromString(std::string challenge)
{
    std::locale loc;
    for (std::string::size_type i=0; i<challenge.length(); ++i)
    std::cout << std::tolower(challenge[i],loc);

    if (challenge == "vowelsquare") {
        return Challenge::VowelSquare;
    } else {
        return Challenge::Unspecified;
    }
}

Solution* getSolverForChallenge(Challenge challenge)
{
    if (challenge == Challenge::Unspecified) {
        challenge = todaysChallenge;
    }

    switch (challenge)
    {
    case Challenge::VowelSquare:
        return new VowelSquare();
    default:
        return nullptr;
    }
}

bool isTestCasePassing(Solution *solver, std::tuple<std::string, std::string> testCase)
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

void testCasePass(std::string in, std::string out)
{
    std::cout << setConsoleGreen << "PASS: " << unsetConsoleColor << in << " -> " << out << "\n";
}

void testCaseFail(std::string in, std::string out, std::string expected)
{
    std::cout << setConsoleRed << "FAIL: " << unsetConsoleColor << in << "\n";
    std::cout << "    expected: " << expected << "\n";
    std::cout << "    actual: " << out << "\n";
}

void ResultSummary(int count, int fail)
{
    std::cout << setConsolePurple << "Summary: " << count << " test cases; " << fail << " tests failed.\n" << unsetConsoleColor;
}
