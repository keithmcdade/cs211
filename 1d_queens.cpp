#include <iostream>
using namespace std;

int main() {

    // N = size of board
    const int N = 8;
    int q[N], c = 0, solutions = 0;
    q[c] = 0;

nc:
    // iterate c, if c == size of board print solution
    c++;
    if (c == N) goto print;
    // enables use of q[c]++ at label nr without skipping 0
    q[c] = -1;

nr:
    q[c]++;
    // if row == size of board there is no valid spot in that col, go back one col
    if (q[c] == N) goto backtrack;
    // row test + diagonal test
    for (int i = 0; i < c; i++)
        // row test | down and left test | up and left test
        // down and left: row # + col #; up and left: row # - col #
        // go back to new row if test fails
        if (q[i] == q[c] || q[i] + i == q[c] + c || q[i] - i == q[c] - c) goto nr;

    goto nc;

backtrack:
    c--;
    // if c < 0 there are no more valid solutions
    if (c == -1) return 0;

    goto nr;

print:
    solutions++;
    cout << endl << "solution #" << solutions << ":" << endl;
    cout << "---------------" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (q[i] == j) cout << 'Q' << ' ';
            else cout << '#' << ' ';
        }
        cout << endl;
    }

    goto backtrack;
}