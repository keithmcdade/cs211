#include <string>
#pragma once
// #ifndef ADD_H
// #define ADD_H

// validates string of numbers for evaluation
bool valid(std::string s);

// adds or subtracts number
std::string add(std::string s1, std::string s2, bool add);

// wrapper that redirects input based on negative or positive quality
std::string add(std::string s1, std::string s2);

// wrapper that does housekeeping for 1 negative and 1 positive number
std::string one_negative(std::string s1, std::string s2);

// wrapper that does some housekeeping for 2 negative numbers
std::string both_negative(std::string s1, std::string s2);

// #endif