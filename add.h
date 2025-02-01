#ifndef ADD_H
#define ADD_H

// validates string of numbers for evaluation
bool valid(string s);

// wrapper that redirects input based on negative or positive quality
string add(string s1, string s2);

// wrapper that does some housekeeping for 2 negative numbers
string add_negative(string s1, string s2);

// wrapper that does housekeeping for 1 negative and 1 positive number
string subtract(string s1, string s2);

// adds or subtracts number
string calculate(string s1, string s2, bool add);

#endif