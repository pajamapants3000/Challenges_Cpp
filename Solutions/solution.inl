/*
 * Template definitions for solution.h
 *
 * TODO: Create unit tests for these!
 */

#include "solution.h"

#include <sstream>
#include <string>
#include <vector>

template <typename T>
void Solution::extractIntMatrix(T** &M, std::size_t &N, const std::string &input, const std::string &caller)
{
    using row_t = std::vector<T>;
    using matrix_t = std::vector<row_t>;

    std::string _caller { caller.empty() ? "Solution" : caller }; // for error messages if any
    matrix_t resultVector {extractIntMatrix<T>(input, caller)};

    typename row_t::size_type cols {resultVector.at(0).size()};
    typename matrix_t::size_type rows {resultVector.size()};
    N = cols>rows?cols:rows;
    M  = new T*[N];
    if (!M) throw "Failed to allocated memory for new matrix array M.";
    for (typename row_t::size_type i {0}; i < N; ++i) {
        M[i] = new T[N];
        if (!(M[i])) throw "Failed to allocated memory for new matrix row array M[i].";
    }
    for (std::size_t i {0}; i < N; ++i) {
        for (std::size_t j {0}; j < N; ++j) {
            M[i][j] = resultVector.at(i).at(j);
        }
    }
}

template <typename T>
std::vector<std::vector<T>> Solution::extractIntMatrix(const std::string &input, const std::string &caller)
{
    using row_t = std::vector<T>;
    using matrix_t = std::vector<row_t>;

    char delim {','};

    std::string _caller { caller.empty() ? "Solution" : caller }; // for error messages if any
    matrix_t result {};

    typename matrix_t::size_type currentRow {0};

    std::stringstream inputStream { input };
    std::string rowInput {};
    std::uint32_t nextIn {0};

    while (std::getline(inputStream, rowInput, delim)) {
        std::stringstream rowStream {rowInput};

        row_t nextRow{};
        result.push_back(nextRow);

        while (rowStream >> nextIn) {
            result.at(currentRow).push_back(nextIn);
        }
        ++currentRow;
    }

    return result;
}

template <typename T>
std::string Solution::arrayToString(T* a, const std::size_t N)
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
std::string Solution::arrayToString(T** a, const std::size_t N1, const std::size_t N2)
{
    std::string result {};

    for (std::size_t i {0}; i < N2; ++i) {
        std::string next {arrayToString(a[i], N1)};
        result.append(next);
        if (i != N2-1) {
            result.append(", ");
        }
    }
    return result;
}

template <typename T>
std::string Solution::arrayToString(std::vector<T> a)
{
    std::string result {};
    typename std::vector<T>::size_type N {a.size()};

    for (std::size_t i {0}; i < N; ++i) {
        result.append(std::to_string(a[i]));
        if (i != N-1) {
            result.append(" ");
        }
    }
    return result;
}

template <typename T>
std::string Solution::arrayToString(std::vector<std::vector<T>> a)
{
    std::string result {};
    typename std::vector<T>::size_type N2 {a.size()};
    typename std::vector<T>::size_type N1 {a.at(0).size()};

    for (std::size_t i {0}; i < N2; ++i) {
        std::string next {arrayToString(a[i], N1)};
        result.append(next);
        if (i != N2-1) {
            result.append(", ");
        }
    }
    return result;
}

template <typename T>
std::vector<std::vector<T>> makeCopy(const std::vector<std::vector<T>>& toCopy)
{
    std::vector<std::vector<T>> result {};
    for (std::vector<T> row : toCopy) {
        result.push_back(makeCopy(row));
    }
}

template <typename T>
std::vector<T> makeCopy(const std::vector<T>& toCopy)
{
    std::vector<T> result {};
    for (std::vector<T> element : toCopy) {
        result.push_back(element);
    }
}
