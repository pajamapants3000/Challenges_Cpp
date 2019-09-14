#include "solution.h"

#include <cmath>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

static const char* wordCharacters { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_" };

Solution::Solution() {}
Solution::~Solution() {}

// TODO: create unit tests!

template<> int stringToAny(const std::string &input, std::string::size_type &position) {
    return std::stoi(input, &position, 10);
}

template<> uint stringToAny(const std::string &input, std::string::size_type &position) {
    return static_cast<uint>(std::stoul(input, &position, 10));
}

template<> long stringToAny(const std::string &input, std::string::size_type &position) {
    return std::stol(input, &position, 10);
}

template<> ulong stringToAny(const std::string &input, std::string::size_type &position) {
    return std::stoul(input, &position, 10);
}

template<> float stringToAny(const std::string &input, std::string::size_type &position) {
    return std::stof(input, &position);
}

template<> double stringToAny(const std::string &input, std::string::size_type &position) {
    return std::stod(input, &position);
}

template<> char stringToAny(const std::string &input, std::string::size_type &position) {
    position = input.find_first_of(wordCharacters, position);
    if (position == std::string::npos) return '\0';
    char result { input.at(position) };
    ++position;
    return result;
}

template<> const char* stringToAny(const std::string &input, std::string::size_type &position) {
    std::string::size_type start { input.find_first_of(wordCharacters) };
    position = input.find_first_not_of(wordCharacters, start);
    const char* result { input.substr(start, position-start).c_str() };
    ++position;
    return result;
}

template<> std::string stringToAny(const std::string &input, std::string::size_type &position) {
    std::string::size_type start { input.find_first_of(wordCharacters) };
    position = input.find_first_not_of(wordCharacters, start);
    std::string result { input.substr(start, position-start) };
    ++position;
    return result;
}

