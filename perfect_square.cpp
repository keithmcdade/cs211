#include <iostream>
using namespace std;

int main() {

    int i = 0;

    while (((i * i) % 100 / 10) % 2 == 0 || ((i * i) % 10) % 2 == 0) i++;

    if ((i * i) / i != i)
        cout << "Error: integer overflow occured when attempting to square " << i << ". " << endl 
             << "A perfect square with the two right most digits being odd could not be found." << endl;
    
    return 0;

}

// output:       -2147479015
// 46341^2:       2147488281 (value for i * i that caused overflow)
// max int size:  2147483648

// 46341^2 - max int size:
// 4633
// 4633 - max int size:
// -2147479015