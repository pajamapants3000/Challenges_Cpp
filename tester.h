// WORK-IN-PROGRESS!
// idea is to have Tester<-SolutionTester<-<>-Asolution, with Tester reusable for other classes, such as LinkedList (SllNode and DllNode)
#ifndef TESTER_H
#define TESTER_H

#include <string>
#include <tuple>
#include <vector>

/* Additional Constants */
constexpr int inputMaxChar { 65536 };
constexpr char setConsoleGreen[] { "\033[0;32m" };
constexpr char setConsoleRed[] { "\033[0;31m" };
constexpr char setConsolePurple[] { "\033[0;35m" };
constexpr char unsetConsoleColor[] { "\033[0m" };
/* ********* */

class Tester
{

public:
    Tester();
    virtual ~Tester();

    virtual void run() = 0;

    template <typename In, typename Out>
    void run_test(Out (*f)(In input), const std::vector<std::tuple<In, Out>> testcases);

    virtual std::string display() const = 0;

private:
    template <typename In, typename Out>
    bool isTestCasePassing(Out (*f)(In input), const std::tuple<In, Out> testcase);

    void printHeader() const;
    void printTestCasePass(const std::string in, const std::string out) const;
    void printTestCaseFail(const std::string in, const std::string out, const std::string expected) const;
    void printSummary(const int count, const int fail) const;
};

#endif // TESTER_H
