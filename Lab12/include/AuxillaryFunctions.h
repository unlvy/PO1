#pragma once

/**
 * @file
 * contains auxillary function and auxillary functions templates
 */

/**
 * returns information whether object was found as std::string
 * @param bool
 * @return std::string
 */
std::string print(bool isFound) {
    return isFound ? "Znaleziono" : "Nie znaleziono";
}

/**
 * template of function used to multiply std::string (standing left of * operator)
 * by given value
 * @param std::string - string to multiply
 * @param T - multipler
 * @return std::string - result
 */
template <typename T> 
std::string operator*(std::string value, T multipler) {
    std::string result;
    for (T i = 0; i < multipler; i++) {
        result += value;
    }
    return result;
}

/**
 * template of function used to multiply std::string (standing right of * operator)
 * by given value
 * @param std::string - string to multiply
 * @param T - multipler
 * @return std::string - result
 */
template <typename T> 
std::string operator*(T multipler, std::string value) {
    std::string result;
    for (T i = 0; i < multipler; i++) {
        result += value;
    }
    return result;
}
