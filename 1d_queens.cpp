#include <iostream>
using namespace std;

int main() {

    const int Q = 8;
    int q[Q], c = 0, solutions = 0;
    q[c] = 0;

nc:
    c++;
    if (c == Q) goto print;
    q[c] = -1;

nr:
    q[c]++;
    if (q[c] == Q) goto backtrack;
    // row test + diagonal test
    

    q[c] = 1;
    goto nc;

backtrack:
    c--;
    if (c == -1) return 0;
    // reset previous queen placement
    q[c] = 0;
    while (q[c] != 1) q[c]++;
    q[c] = 0;
    
    goto nr;

print:
    solutions++;
    cout << endl << "solution #" << solutions << ":" << endl;
    cout << "---------------" << endl;
    for (int i = 0; i < Q; i++) {
        // print
    }
    
    goto backtrack;
}