#include <iostream>
using namespace std;

int main() {

    // const Q represents size of board / amount of queens
    const int Q = 8;
    int b[Q][Q] = {0}, c = 0, r, solutions = 0;
    b[0][0] = 1;

nc:
    c++;
    // solution is true if c goes out of bounds, goto print
    if (c == Q) goto print;
    r = -1;

nr:
    r++;
    if (r == Q) goto backtrack;
    // row test
    for (int i = 0; i < c; i++) 
        if (b[r][i] == 1) goto nr;
    // up and left
    for (int i = 1; (r - i) >= 0 and (c - i) >= 0; i++) 
        if (b[r - i][c - i] == 1) goto nr;
    // down and left
    for (int i = 1; (r + i) < Q and (c - i) >= 0; i++) 
        if (b[r + i][c - i] == 1) goto nr;
    // place queen
    b[r][c] = 1;
    goto nc;

backtrack:
    c--;
    // end program if c backtracks to -1
    if (c == -1) return 0;
    // reset previous queen placement
    r = 0;
    while (b[r][c] != 1) r++;
    b[r][c] = 0;
    
    goto nr;

print:
    // print b w/ solution #
    solutions++;
    cout << endl << "solution #" << solutions << ":" << endl;
    cout << "---------------" << endl;
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < Q; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    // backtrack until all solutions are printed
    goto backtrack;
}