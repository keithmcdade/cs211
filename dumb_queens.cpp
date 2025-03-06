#include <iostream>
using namespace std;

bool ok(int q[], int n);
void print(int q[], int n, int &solutions);

int main() {

    const int n = 8;
    int q[8], solutions = 0;

    for (int i0 = 0; i0 < n; i0++) {
        for (int i1 = 0; i1 < n; i1++) {
            for (int i2 = 0; i2 < n; i2++) {
                for (int i3 = 0; i3 < n; i3++) {
                    for (int i4 = 0; i4 < n; i4++) {
                        for (int i5 = 0; i5 < n; i5++) {
                            for (int i6 = 0; i6 < n; i6++) {
                                for (int i7 = 0; i7 < n; i7++) {
                                    q[0] = i0;
                                    q[1] = i1;
                                    q[2] = i2;
                                    q[3] = i3;
                                    q[4] = i4;
                                    q[5] = i5;
                                    q[6] = i6;
                                    q[7] = i7;
                                    if (ok(q, n)) print(q, n, solutions);
                                }
                            }                           
                        }
                    }
                }
            }
        }
    }
}

bool ok(int q[], int n) {

    for (int c = n - 1; c >= 0; c--) {
        for (int i = 0; i < c; i++) {
            if (q[i] == q[c] || c - i == abs(q[c] - q[i])) return false;
        }
    }
    return true;
}

void print(int q[], int n, int &solutions) {
    solutions++;
    cout << endl << "solution #" << solutions << ":" << endl;
    cout << "---------------" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (q[i] == j) cout << '1' << ' ';
            else cout << '0' << ' ';
        }
        cout << endl;
    }
}
