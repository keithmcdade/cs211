#include <iostream>
#include "biginteger.h"
using namespace std;

bool valid(string s);
string add(string s1, string s2, bool add);
string add(string s1, string s2);
string one_negative(string s1, string s2);
string both_negative(string s1, string s2);

int main () {

    string s1, s2, result;

    cout << "Enter two numbers (up to 100 digits): " << endl;
    cin >> s1 >> s2;

    // validate user input, exit with error message if false
    if (!valid(s1) || !valid(s2)) {
        cout << "Bad input." << endl;
        return 0;
    }

    result = add(s1, s2);
    cout << result << endl;

    return 0;
}

bool valid(string s) {
    // check length is <= 100
    if ((s[0] == '-' && s.length() > 101) || s.length() > 100) return false;

    // return false if number contains invalid characters or leading zeros
    size_t found = s.find_first_not_of("-0123456789");
    if (found != string::npos) return false;

    found = s.find_first_not_of("0");
    if (found != 0 && s.compare("0") != 0) return false;

    found = s.rfind("-");
    if ((found != 0 && found != string::npos) || s.compare("-0") == 0 || s.compare("-") == 0) return false;

    return true;
}

string add(string s1, string s2, bool add) {

    string result;

    int p1 = s1.length() - 1, 
        p2 = s2.length() - 1,
        carry = 0;

    while (p1 > -1 || p2 > -1) {

        // check for value at current pointer for each string, 
        // set to int if true or 0 if false
        int n1 = (p1 >= 0) ? s1[p1] - '0' : 0,
            n2 = (p2 >= 0) ? s2[p2] - '0' : 0,
            sum = (add) ? n1 + n2 : n1 - n2;

        sum += carry;
        // determine carry digit: 1 for sum > 10, -1 for sum < 0, else 0
        if (sum >= 10) carry = 1;
        else if (sum < 0) carry = -1;
        else carry = 0;

        // for subtracting, if sum is less than 0 add 10, -1 will carry over
        // for adding, keep last digit of sum, 1 will carry over
        sum = (!add && sum < 0) ? sum + 10 : sum % 10;
        // append sum to left side of result
        result = to_string(sum) + result;

        p1--; p2--;
    }

    // add leftover carry digit
    if (!add && carry) result[0] = (char)(1 + '0');
    else if (carry == 1) result = to_string(carry) + result;

    return result;
}

string add(string s1, string s2) {
    // wrapper function to direct input to correct wrapper function
    string result;

    bool is_s1_negative = (s1[0] == '-') ? true : false, 
         is_s2_negative = (s2[0] == '-') ? true : false;

    if (is_s1_negative && is_s2_negative) result = both_negative(s1, s2); // both numbers negative
    else if (is_s1_negative || is_s2_negative) result = (is_s1_negative) ? one_negative(s2, s1) : one_negative(s1, s2); // one number negative 
    else result = add(s1, s2, true); // both numbers positive
    
    return result;
}

string one_negative(string s1, string s2) {
    // wrapper function for calling add() on 1 negative and 1 positive number
    string result;
    s2.erase(0, 1);

    // check if negative number is larger, result will be negative if true
    bool is_negative;
    if (s2.length() == s1.length()) is_negative = (s2[0] > s1[0]) ? true : false;
    else is_negative = (s2.length() > s1.length()) ? true : false;

    // if both numbers are the same just return 0
    if (s1.compare(s2) == 0) return "0";

    // swap if s2 is larger than s1
    if (is_negative) swap(s1, s2);
    result = add(s1, s2, false);
    
    // remove leading zeros
    result.erase(0, result.find_first_not_of('0'));
    
    if (is_negative) result.insert(0, 1, '-');
    return result;
}

string both_negative(string s1, string s2) {
    // wrapper function for calling add() on 2 negative numbers
    string result;
        
    s1.erase(0, 1);
    s2.erase(0, 1);
    
    result = add(s1, s2, true);
    result.insert(0, 1, '-');

    return result;

}
