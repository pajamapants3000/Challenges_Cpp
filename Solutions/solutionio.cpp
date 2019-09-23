#include "solutionio.h"

// TODO: create unit tests!

static const char* wordCharacters { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_" };

template<> const std::string to_string(char in) { return std::string(1, in); }

template<> int stringToAny<int>(const std::string &input, std::string::size_type &position) {
    return std::stoi(input, &position, 10);
}

template<> uint stringToAny<uint>(const std::string &input, std::string::size_type &position) {
    return static_cast<uint>(std::stoul(input, &position, 10));
}

template<> long stringToAny<long>(const std::string &input, std::string::size_type &position) {
    return std::stol(input, &position, 10);
}

template<> ulong stringToAny<ulong>(const std::string &input, std::string::size_type &position) {
    return std::stoul(input, &position, 10);
}

template<> float stringToAny<float>(const std::string &input, std::string::size_type &position) {
    return std::stof(input, &position);
}

template<> double stringToAny<double>(const std::string &input, std::string::size_type &position) {
    return std::stod(input, &position);
}

template<> char stringToAny<char>(const std::string &input, std::string::size_type &position) {
    position = input.find_first_of(wordCharacters, position);
    if (position == std::string::npos) return '\0';
    char result { input.at(position) };
    ++position;
    return result;
}

template<> const char* stringToAny<const char*>(const std::string &input, std::string::size_type &position) {
    std::string::size_type start { input.find_first_of(wordCharacters) };
    position = input.find_first_not_of(wordCharacters, start);
    const char* result { input.substr(start, position-start).c_str() };
    return result;
}

template<> std::string stringToAny<std::string>(const std::string &input, std::string::size_type &position) {
    std::string::size_type start { input.find_first_of(wordCharacters) };
    position = input.find_first_not_of(wordCharacters, start);
    std::string result { input.substr(start, position-start) };
    return result;
}
