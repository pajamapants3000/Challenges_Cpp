#ifndef SOLUTIONIO_H
#define SOLUTIONIO_H

#include <string>
#include <vector>
#include <tuple>
#include <iostream>

template <typename T>
T stringToAny(const std::string &/*input*/, std::string::size_type &/*position*/)
{
    throw "stringToAny not implemented for type.";
}
template<> int stringToAny<int>(const std::string &input, std::string::size_type &position);
template<> uint stringToAny<uint>(const std::string &input, std::string::size_type &position);
template<> long stringToAny<long>(const std::string &input, std::string::size_type &position);
template<> ulong stringToAny<ulong>(const std::string &input, std::string::size_type &position);
template<> float stringToAny<float>(const std::string &input, std::string::size_type &position);
template<> double stringToAny<double>(const std::string &input, std::string::size_type &position);
template<> char stringToAny<char>(const std::string &input, std::string::size_type &position);
template<> const char* stringToAny<const char*>(const std::string &input, std::string::size_type &position);
template<> std::string stringToAny<std::string>(const std::string &input, std::string::size_type &position);

template <typename T>
const std::string to_string(T in)
{
    return std::to_string(in);
}

template<> const std::string to_string<char>(char in);

template <typename T>
const std::vector<T> extractArray(const std::string &input, const std::string &caller = "Solution")
{
    std::vector<T> result {};
    T next;
    std::string::size_type pos {0};

    try {
        while (pos < input.size()) {
            std::string::size_type nextpos {0};
            next = stringToAny<T>(input.substr(pos), nextpos);
            result.push_back(next);

            if (nextpos == std::string::npos) break;
            pos += nextpos+1;
        }
    } catch (const std::invalid_argument& ia) {
        std::cerr << caller << ": Invalid input: " << ia.what() << "\n";
        exit(1);
    } catch (const std::out_of_range& oor) {
        std::cerr << caller << ": Input out of range: " << oor.what() << "\n";
        exit(1);
    } catch (const std::exception& ex) {
        std::cerr << caller << ": " << ex.what() << "\n";
        exit(1);
    } catch (const char* str) {
        std::cerr << caller << ": " << str << "\n";
        exit(1);
    } catch (...) {
        std::cerr << caller << ": Failed to parse from input.\n";
        exit(1);
    }
    return result;
}

template <typename T>
std::vector<std::vector<T>> extractMatrix(const std::string &input, const std::string &caller = "Solution")
{
    std::vector<std::vector<T>> result {};
    std::string::size_type pos {0};

    while (pos < input.size()) {
        std::string::size_type nextPos {input.find_first_of(",", pos)};
        result.push_back(extractArray<T>(input.substr(pos, nextPos-pos), caller));
        if (nextPos == std::string::npos) break;
        pos = nextPos+1;
    }
    return result;
}

template <typename T>
void extractArray(T* &a, std::size_t &N, const std::string &input, const std::string &caller = "Solution")
{
    std::vector<T> resultVector { extractArray<T>(input, caller) };
    N = resultVector.size();
    a = new T[N];
    for (typename std::vector<T>::size_type i {0}; i < N; ++i) {
        a[i] = resultVector.at(i);
    }
}

template <typename T>
void extractMatrix(T** &a, std::size_t &N, const std::string &input, const std::string &caller = "Solution")
{
    std::vector<std::vector<T>> resultVector { extractMatrix<T>(input, caller) };
    N = resultVector.size();
    a = new T*[N];
    for (typename std::vector<std::vector<T>>::size_type i {0}; i < N; ++i) {
        a[i] = new T[N];
        for (typename std::vector<T>::size_type j {0}; j < N; ++j) {
            a[i][j] = resultVector.at(i).at(j);
        }
    }
}

template <typename T>
std::string arrayToString(T* a, const std::size_t N)
{
    std::string result {};

    for (std::size_t i {0}; i < N; ++i) {
        result.append(to_string(a[i]));
        if (i != N-1) {
            result.append(" ");
        }
    }
    return result;
}

template <typename T>
std::string matrixToString(T** a, const std::size_t N1, const std::size_t N2)
{
    std::string result {};

    for (std::size_t i {0}; i < N2; ++i) {
        std::string next {arrayToString<T>(a[i], N1)};
        result.append(next);
        if (i != N2-1) {
            result.append(", ");
        }
    }
    return result;
}

template <typename T>
std::string arrayToString(std::vector<T> a)
{
    std::string result {};

    for (std::size_t i {0}; i < a.size(); ++i) {
        result.append(to_string(a.at(i)));
        if (i != (a.size()-1)) {
            result.append(" ");
        }
    }
    return result;
}

template <typename T>
std::string matrixToString(std::vector<std::vector<T>> a)
{
    std::string result {};

    for (std::size_t i {0}; i < a.size(); ++i) {
        std::string next {arrayToString<T>(a.at(i))};
        result.append(next);
        if (i != (a.size()-1)) {
            result.append(", ");
        }
    }
    return result;
}

template <typename T>
std::vector<T> arrayCopy(const std::vector<T>& toCopy)
{
    std::vector<T> result {};
    for (T element : toCopy) {
        result.push_back(element);
    }
    return result;
}

template <typename T>
std::vector<std::vector<T>> matrixCopy(const std::vector<std::vector<T>>& toCopy)
{
    std::vector<std::vector<T>> result {};
    for (std::vector<T> row : toCopy) {
        result.push_back(arrayCopy(row));
    }
    return result;
}

#endif // SOLUTIONIO_H
