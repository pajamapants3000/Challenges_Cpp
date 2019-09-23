#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <locale>

#include "sort.h"
#include "Solutions/solutionio.h"

/* Specify which sort algorithm to test here */
static const SortAlgorithm todaysAlgorithm { SortAlgorithm::BUMerge };
/* ******************************************** */

/* Additional Constants */
constexpr char setConsoleGreen[] { "\033[0;32m" };
constexpr char setConsoleRed[] { "\033[0;31m" };
constexpr char setConsolePurple[] { "\033[0;35m" };
constexpr char unsetConsoleColor[] { "\033[0m" };
/* ********* */

class NoCompare
{
private:
    int someval;
public:
    NoCompare() : someval{0} { someval = 0;}
    bool operator==(NoCompare other) { return this->someval == other.someval; }
    bool operator!=(NoCompare other) { return !(*this == other); }
    static const std::string to_string(NoCompare /*in*/) {return "NoCompare";}
};

class Comparable
{
    int someval;
    static int counter;

public:
    Comparable() : someval{0} { int counter {0}; ++counter; someval = counter;}
    Comparable(int aval) : someval{aval} { }
    bool operator<(const Comparable other) const { return this->someval < other.someval; }
    bool operator==(const Comparable other) const { return this->someval == other.someval; }
    bool operator!=(const Comparable other) const { return !(*this == other); }
    int val() { return this->someval; }
    static const std::string to_string(Comparable in) {return "Comparable(" + std::to_string(in.val()) + ")";}
};

/* Forward Declarations */
template <typename T>
bool isTestCasePassing(std::tuple<T*, T*, size_t> testCase);
template <typename T>
bool isLLTestCasePassing(std::tuple<typename Sort<T>::Node*, typename Sort<T>::Node*> testCase);
template <typename T>
void testCasePass(T* in, T* out, size_t N);
template <typename T>
void testCaseFail(T* in, T* out, T* expected, size_t N);
template <typename T>
std::vector<std::tuple<T*, T*, size_t>> getTestCases();
template <typename T>
std::vector<std::tuple<typename Sort<T>::Node*, typename Sort<T>::Node*>> getLLTestCases();
template <typename T>
void runTest(int& testCaseCount, int& testCaseFailCount);
template <typename T>
void runLLTest(int& testCaseCount, int& testCaseFailCount);
void runTests(int& testCaseCount, int& testCaseFailCount);
void runLLTests(int& testCaseCount, int& testCaseFailCount);
void ResultSummary(int count, int fail);
bool doesAlgorithmSupportLinkedLists(SortAlgorithm kind);
/* ******************** */

template<> const std::string to_string<NoCompare>(NoCompare in)
{
    return NoCompare::to_string(in);
}

template<> const std::string to_string<Comparable>(Comparable in)
{
    return Comparable::to_string(in);
}

template <>
std::vector<std::tuple<std::int64_t*, std::int64_t*, size_t>> getTestCases<std::int64_t>()
{
    std::vector<std::tuple<std::int64_t*, std::int64_t*, size_t>> result;
    result.push_back(std::make_tuple(new std::int64_t[5] {2, 1, 0, -1, -2},
                                     new std::int64_t[5] {-2, -1, 0, 1, 2},
                                     5));
    return result;
}

template <>
std::vector<std::tuple<size_t*, size_t*, size_t>> getTestCases<size_t>()
{
    std::vector<std::tuple<size_t*, size_t*, size_t>> result;
    result.push_back(std::make_tuple(new size_t[5] {5, 4, 3, 2, 1},
                                     new size_t[5] {1, 2, 3, 4, 5},
                                     5));
    return result;
}

template <>
std::vector<std::tuple<char*, char*, size_t>> getTestCases<char>()
{
    std::vector<std::tuple<char*, char*, size_t>> result;
    result.push_back(std::make_tuple(new char[5] {'e', 'd', 'c', 'b', 'a'},
                                     new char[5] {'a', 'b', 'c', 'd', 'e'},
                                     5));
    return result;
}

template <>
std::vector<std::tuple<bool*, bool*, size_t>> getTestCases<bool>()
{
    std::vector<std::tuple<bool*, bool*, size_t>> result;
    result.push_back(std::make_tuple(new bool[5] {1, 1, 1, 0, 0},
                                     new bool[5] {0, 0, 1, 1, 1},
                                     5));
    return result;
}

template <>
std::vector<std::tuple<NoCompare*, NoCompare*, size_t>> getTestCases<NoCompare>()
{
    std::vector<std::tuple<NoCompare*, NoCompare*, size_t>> result;
    result.push_back(std::make_tuple(new NoCompare[3] { NoCompare(), NoCompare(), NoCompare() },
                                     new NoCompare[3] { NoCompare(), NoCompare(), NoCompare() },
                                     3));
    return result;
}

template <>
std::vector<std::tuple<Comparable*, Comparable*, size_t>> getTestCases<Comparable>()
{
    std::vector<std::tuple<Comparable*, Comparable*, size_t>> result;
    result.push_back(std::make_tuple(new Comparable[5] { Comparable(5), Comparable(4), Comparable(3), Comparable(2), Comparable(1) },
                                     new Comparable[5] { Comparable(1), Comparable(2), Comparable(3), Comparable(4), Comparable(5) },
                                     5));
    return result;
}

template <>
std::vector<std::tuple<typename Sort<std::int64_t>::Node*, typename Sort<std::int64_t>::Node*>> getLLTestCases<std::int64_t>()
{
    std::vector<std::tuple<typename Sort<std::int64_t>::Node*, typename Sort<std::int64_t>::Node*>> result;
    result.push_back(std::make_tuple(Sort<std::int64_t>::Node::fromArray(new std::int64_t[5] {2, 1, 0, -1, -2}, 5),
                                     Sort<std::int64_t>::Node::fromArray(new std::int64_t[5] {-2, -1, 0, 1, 2}, 5)));
    return result;
}

template <>
std::vector<std::tuple<typename Sort<size_t>::Node*, typename Sort<size_t>::Node*>> getLLTestCases<size_t>()
{
    std::vector<std::tuple<typename Sort<size_t>::Node*, typename Sort<size_t>::Node*>> result;
    result.push_back(std::make_tuple(Sort<size_t>::Node::fromArray(new size_t[5] {5, 4, 3, 2, 1}, 5),
                                     Sort<size_t>::Node::fromArray(new size_t[5] {1, 2, 3, 4, 5}, 5)));
    return result;
}

template <>
std::vector<std::tuple<typename Sort<char>::Node*, typename Sort<char>::Node*>> getLLTestCases<char>()
{
    std::vector<std::tuple<typename Sort<char>::Node*, typename Sort<char>::Node*>> result;
    result.push_back(std::make_tuple(Sort<char>::Node::fromArray(new char[5] {'e', 'd', 'c', 'b', 'a'}, 5),
                                     Sort<char>::Node::fromArray(new char[5] {'a', 'b', 'c', 'd', 'e'}, 5)));
    return result;
}

template <>
std::vector<std::tuple<typename Sort<bool>::Node*, typename Sort<bool>::Node*>> getLLTestCases<bool>()
{
    std::vector<std::tuple<typename Sort<bool>::Node*, typename Sort<bool>::Node*>> result;
    result.push_back(std::make_tuple(Sort<bool>::Node::fromArray(new bool[5] {1, 1, 1, 0, 0}, 5),
                                     Sort<bool>::Node::fromArray(new bool[5] {0, 0, 1, 1, 1}, 5)));
    return result;
}

template <>
std::vector<std::tuple<typename Sort<NoCompare>::Node*, typename Sort<NoCompare>::Node*>> getLLTestCases<NoCompare>()
{
    std::vector<std::tuple<typename Sort<NoCompare>::Node*, typename Sort<NoCompare>::Node*>> result;
    result.push_back(std::make_tuple(Sort<NoCompare>::Node::fromArray(new NoCompare[3] { NoCompare(), NoCompare(), NoCompare() }, 3),
                                     Sort<NoCompare>::Node::fromArray(new NoCompare[3] { NoCompare(), NoCompare(), NoCompare() }, 3)));
    return result;
}

template <>
std::vector<std::tuple<typename Sort<Comparable>::Node*, typename Sort<Comparable>::Node*>> getLLTestCases<Comparable>()
{
    std::vector<std::tuple<typename Sort<Comparable>::Node*, typename Sort<Comparable>::Node*>> result;
    result.push_back(std::make_tuple(Sort<Comparable>::Node::fromArray(new Comparable[5] { Comparable(5), Comparable(4), Comparable(3), Comparable(2), Comparable(1) }, 5),
                                     Sort<Comparable>::Node::fromArray(new Comparable[5] { Comparable(1), Comparable(2), Comparable(3), Comparable(4), Comparable(5) }, 5)));
    return result;
}

bool doesAlgorithmSupportLinkedLists(SortAlgorithm kind)
{
    if (kind == SortAlgorithm::BUMerge) return true;
    return false;
}

int main(int /*argc*/, char */*argv*/[])
{
    int testCaseCount {0};
    int testCaseFailCount {0};

    if (doesAlgorithmSupportLinkedLists(todaysAlgorithm)) {
        runLLTests(testCaseCount, testCaseFailCount);
    }
    runTests(testCaseCount, testCaseFailCount);


    ResultSummary(testCaseCount, testCaseFailCount);
    return 0;
}

void runTests(int& testCaseCount, int& testCaseFailCount)
{
    try {
        runTest<std::int64_t>(testCaseCount, testCaseFailCount);
        runTest<size_t>(testCaseCount, testCaseFailCount);
        runTest<char>(testCaseCount, testCaseFailCount);
        runTest<bool>(testCaseCount, testCaseFailCount);
        //runTest<NoCompare>(testCaseCount, testCaseFailCount);
        runTest<Comparable>(testCaseCount, testCaseFailCount);
    } catch (char const* msg) {
        std::cout << msg;
    }
}

void runLLTests(int& testCaseCount, int& testCaseFailCount)
{
    try {
        runLLTest<std::int64_t>(testCaseCount, testCaseFailCount);
        runLLTest<size_t>(testCaseCount, testCaseFailCount);
        runLLTest<char>(testCaseCount, testCaseFailCount);
        runLLTest<bool>(testCaseCount, testCaseFailCount);
        //runLLTest<NoCompare>(testCaseCount, testCaseFailCount);
        runLLTest<Comparable>(testCaseCount, testCaseFailCount);
    } catch (char const* msg) {
        std::cout << msg;
    }
}

template <typename T>
void runTest(int& testCaseCount, int& testCaseFailCount)
{
    for (std::tuple<T*, T*, size_t> testcase : getTestCases<T>()) {
        if (!isTestCasePassing<T>(testcase)) {
            ++testCaseFailCount;
        }
        ++testCaseCount;
    }
}

template <typename T>
void runLLTest(int& testCaseCount, int& testCaseFailCount)
{
    using Node_t = typename Sort<T>::Node;
    for (std::tuple<Node_t*, Node_t*> testcase : getLLTestCases<T>()) {
        if (!isLLTestCasePassing<T>(testcase)) {
            ++testCaseFailCount;
        }
        ++testCaseCount;
    }
}

template <typename T>
bool isTestCasePassing(std::tuple<T*, T*, size_t> testcase)
{
    T* in { std::get<0>(testcase) };
    T* expected { std::get<1>(testcase) };
    size_t N { std::get<2>(testcase) };

    Sort<T> sorter { in, N, todaysAlgorithm };

    T* out { sorter.getSorted() };

    if (Sort<T>::equals(out, expected, N)) {
        testCasePass(in, out, N);
        return true;
    }

    testCaseFail(in, out, expected, N);
    return false;
}

template <typename T>
bool isLLTestCasePassing(std::tuple<typename Sort<T>::Node*, typename Sort<T>::Node*> testcase)
{
    typename Sort<T>::Node* in { std::get<0>(testcase) };
    typename Sort<T>::Node* expected { std::get<1>(testcase) };

    Sort<T> sorter { in, todaysAlgorithm };

    typename Sort<T>::Node* out { sorter.getLLSorted() };

    std::size_t N {0};
    T* inArray = Sort<T>::Node::toArray(in, N);
    T* outArray = Sort<T>::Node::toArray(out, N);
    T* expectedArray = Sort<T>::Node::toArray(expected, N);

    if (Sort<T>::equals(out, expected)) {
        testCasePass(inArray, outArray, N);
        return true;
    }

    testCaseFail(inArray, outArray, expectedArray, N);

    delete[] inArray;
    delete[] outArray;
    delete[] expectedArray;
    return false;
}

template <typename T>
void testCasePass(T* in, T* out, size_t N)
{
    std::cout << setConsoleGreen << "PASS: " << unsetConsoleColor << arrayToString(in, N) << " -> " << arrayToString(out, N) << "\n";
}

template <typename T>
void testCaseFail(T* in, T* out, T* expected, size_t N)
{
    std::cout << setConsoleRed << "FAIL: " << unsetConsoleColor << arrayToString(in, N) << "\n";
    std::cout << "    expected: " << arrayToString(expected, N) << "\n";
    std::cout << "    actual: " << arrayToString(out, N) << "\n";
}

void ResultSummary(int count, int fail)
{
    std::cout << setConsolePurple << "Summary: " << count << " test cases; " << fail << " tests failed.\n" << unsetConsoleColor;
}
