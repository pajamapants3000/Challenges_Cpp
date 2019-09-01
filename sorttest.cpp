#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <locale>

#include "sort.h"

/* Specify which sort algorithm to test here */
static const SortAlgorithm todaysAlgorithm { SortAlgorithm::Heap };
/* ******************************************** */

/* Additional Constants */
constexpr char setConsoleGreen[] { "\033[0;32m" };
constexpr char setConsoleRed[] { "\033[0;31m" };
constexpr char setConsolePurple[] { "\033[0;35m" };
constexpr char unsetConsoleColor[] { "\033[0m" };
/* ********* */

/* Forward Declarations */
template <typename T>
bool isTestCasePassing(std::tuple<T*, T*, size_t> testCase);
template <typename T>
void testCasePass(T* in, T* out, size_t N);
template <typename T>
void testCaseFail(T* in, T* out, T* expected, size_t N);
template <typename T>
bool equals(T* in, T* out, size_t N);
template <typename T>
std::vector<std::tuple<T*, T*, size_t>> getTestCases();
void ResultSummary(int count, int fail);
/* ******************** */

class NoCompare
{
private:
    int someval;
public:
    NoCompare() : someval{0} { someval = 0;}
    bool operator==(NoCompare other) { return this->someval == other.someval; }
    bool operator!=(NoCompare other) { return !(*this == other); }
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
};

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

int main(int /*argc*/, char */*argv*/[])
{
    int testCaseCount {0};
    int testCaseFailCount {0};

    try {
        std::vector<std::tuple<std::int64_t*, std::int64_t*, size_t>> testCases_int { getTestCases<std::int64_t>() };
        std::vector<std::tuple<size_t*, size_t*, size_t>> testCases_uint { getTestCases<size_t>() };
        std::vector<std::tuple<char*, char*, size_t>> testCases_char { getTestCases<char>() };
        std::vector<std::tuple<bool*, bool*, size_t>> testCases_bool { getTestCases<bool>() };
        std::vector<std::tuple<NoCompare*, NoCompare*, size_t>> testCases_nocompare { getTestCases<NoCompare>() };
        std::vector<std::tuple<Comparable*, Comparable*, size_t>> testCases_comparable { getTestCases<Comparable>() };

        for (std::tuple<std::int64_t*, std::int64_t*, size_t> testcase : testCases_int) {
            if (!isTestCasePassing<std::int64_t>(testcase)) {
                ++testCaseFailCount;
            }
            ++testCaseCount;
        }
        for (std::tuple<size_t*, size_t*, size_t> testcase : testCases_uint) {
            if (!isTestCasePassing<std::size_t>(testcase)) {
                ++testCaseFailCount;
            }
            ++testCaseCount;

        }
        for (std::tuple<char*, char*, size_t> testcase : testCases_char) {
            if (!isTestCasePassing<char>(testcase)) {
                ++testCaseFailCount;
            }
            ++testCaseCount;

        }
        for (std::tuple<bool*, bool*, size_t> testcase : testCases_bool) {
            if (!isTestCasePassing<bool>(testcase)) {
                ++testCaseFailCount;
            }
            ++testCaseCount;

        }

        /* This is just here to confirm compile fails
        for (std::tuple<NoCompare*, NoCompare*, size_t> testcase : testCases_nocompare) {
            if (!isTestCasePassing<NoCompare>(testcase)) {
                ++testCaseFailCount;
            }
            ++testCaseCount;

        }
        */

        for (std::tuple<Comparable*, Comparable*, size_t> testcase : testCases_comparable) {
            if (!isTestCasePassing<Comparable>(testcase)) {
                ++testCaseFailCount;
            }
            ++testCaseCount;

        }

    } catch (char const* msg) {
        std::cout << msg;
    }

    ResultSummary(testCaseCount, testCaseFailCount);
    return 0;
}


template <typename T>
bool isTestCasePassing(std::tuple<T*, T*, size_t> testcase)
{
    T* in { std::get<0>(testcase) };
    T* expected { std::get<1>(testcase) };
    size_t N { std::get<2>(testcase) };

    Sort<T> sorter { in, N, todaysAlgorithm };

    T* out { sorter.getSorted() };

    if (equals(out, expected, N)) {
        testCasePass(in, out, N);
        return true;
    }

    testCaseFail(in, out, expected, N);
    return false;
}

std::string arrToString(std::int64_t* a, size_t N)
{
    std::string result;
    result.append("{");
    for (size_t i {0}; i<N; ++i) {
        if (i != 0) {
            result.append(", ");
        }
        result.append(std::to_string(a[i]));
    }
    result.append("}");
    return result;
}

std::string arrToString(size_t* a, size_t N)
{
    std::string result;
    result.append("{");
    for (size_t i {0}; i<N; ++i) {
        if (i != 0) {
            result.append(", ");
        }
        result.append(std::to_string(a[i]));
    }
    result.append("}");
    return result;
}

std::string arrToString(char* a, size_t N)
{
    std::string result;
    result.append(a, N);
    return result;
}

std::string arrToString(bool* a, size_t N)
{
    std::string result;
    result.append("{");
    for (size_t i {0}; i<N; ++i) {
        if (i != 0) {
            result.append(", ");
        }
        result.append(a[i] ? "1" : "0");
    }
    result.append("}");
    return result;
}

std::string arrToString(NoCompare* /*a*/, size_t N)
{
    std::string result;
    result.append("{");
    for (size_t i {0}; i<N; ++i) {
        if (i != 0) {
            result.append(", ");
        }
        result.append("NoCompare");
    }
    result.append("}");
    return result;
}

std::string arrToString(Comparable* a, size_t N)
{
    std::string result;
    result.append("{");
    for (size_t i {0}; i<N; ++i) {
        if (i != 0) {
            result.append(", ");
        }
        result.append(std::to_string(a[i].val()));
    }
    result.append("}");
    return result;
}

template <typename T>
void testCasePass(T* in, T* out, size_t N)
{
    std::cout << setConsoleGreen << "PASS: " << unsetConsoleColor << arrToString(in, N) << " -> " << arrToString(out, N) << "\n";
}

template <typename T>
void testCaseFail(T* in, T* out, T* expected, size_t N)
{
    std::cout << setConsoleRed << "FAIL: " << unsetConsoleColor << arrToString(in, N) << "\n";
    std::cout << "    expected: " << arrToString(expected, N) << "\n";
    std::cout << "    actual: " << arrToString(out, N) << "\n";
}

template <typename T>
bool equals(T* in, T* out, size_t N)
{
    for (size_t i {0}; i < N; ++i) {
        if (in[i] != out[i]) {
            return false;
        }
    }
    return true;
}

void ResultSummary(int count, int fail)
{
    std::cout << setConsolePurple << "Summary: " << count << " test cases; " << fail << " tests failed.\n" << unsetConsoleColor;
}
