#include <iostream>
using namespace std;

bool ok(int q[], int c);
void print(int q[], int N, int solutions);

int main() {

    // N = size of board
    const int N = 8;
    int q[N], c = 0, solutions = 0;
    q[c] = 0;

    while (c >= 0) {
        
        c++;
        // if c == N print solution
        if (c == N) {
            print(q, N, ++solutions); // increment solutions before print is called
            c--;
        } else q[c] = -1;
        
        while (q[c] < 8) {
            q[c]++;
            // if row == N there is no valid spot in that column, backtrack
            if (q[c] == N) {
                c--;
                continue;
            }
            if (ok(q, c)) break;
        }
    }
    return 0;
}

bool ok(int q[], int c) {

    for (int i = 0; i < c; i++)
    // return false if either test fails
    if (q[i] == q[c] || c - i == abs(q[c] - q[i]))
        return false;
    
    return true;
}

void print(int q[], int N, int solutions) {

    cout << endl << "solution #" << solutions << ":" << endl;
    cout << "---------------" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (q[j] == i) cout << '1' << ' ';
            else cout << '0' << ' ';
        }
        cout << endl;
    }
}
