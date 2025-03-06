#include <iostream>
using namespace std;

bool ok(int q[], int c);
void print(int q[], int n, int solutions);

int main() {

    // n = size of board
    const int n = 8;
    int q[n], c = 0, solutions = 0;
    q[c] = 1;

    while (c >= 0) {
        
        c++;
        // if c == n print solution
        if (c == n) {
            print(q, n, ++solutions); // increment solutions before print is called
            c--;
        } else q[c] = 0;
        
        while (q[c] < n + 1) {
            q[c]++;
            // if q[c] == n there is no valid number for that box, backtrack
            if (q[c] == n + 1) {
                c--;
                continue;
            }
            if (ok(q, c)) break;
        }
    }
    return 0;
}

bool ok(int q[], int c) {

    /* 
    adjacency table:
        # 0 1 #
        2 3 4 5
        # 6 7 #
    */  
    int a[8][5] = {{-1}, {0, -1}, {0, -1}, {0, 1, 2, -1}, {0, 1, 3, -1}, {1, 4, -1}, {2, 3, 4, -1}, {3, 4, 5, 6, -1}};
    
    // "row" test
    for (int i = 0; i < c; i++) {
        if (q[c] == q[i]) return false;
    }
    
    int i = 0;
    // adjacency test - a[c][i] == adjacent box to check
    while (a[c][i] != -1) {
        if (abs(q[c] - q[a[c][i]]) == 1) 
            return false;
        i++;
    }

    return true;
}

void print(int q[], int n, int solutions) {

    cout << endl << "solution #" << solutions << ":" << endl;
    cout << "------------" << endl;

    for (int i = 0; i < n; i++) {
        if (i == 0 || i == 6) cout << "# " << q[i] << " ";
        else if (i == 1 || i == 7) cout << q[i] << " #" << endl;
        else if (i == 5) cout << q[i] << endl;
        else cout << q[i] << " ";
    }
}