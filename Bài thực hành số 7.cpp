#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int q[100], n;

bool place(int r, int c) {
    for (int i = 1; i <= r - 1; ++i) {
        if (q[i] == c || abs(q[i] - c) == abs(i - r)) {
            return false;
        }
    }
    return true;
}

void printSolution() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (q[i] == j) {
                cout << "1 ";
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void nQueen(int k) {
    for (int i = 1; i <= n; ++i) {
        if (place(k, i)) {
            q[k] = i;
            if (k == n) {
                printSolution();
            }
            else {
                nQueen(k + 1);
            }
        }
    }
}

int main() {
    cout << "Nhập số lượng con hậu: ";
    cin >> n;
    nQueen(1);
    return 0;
}
