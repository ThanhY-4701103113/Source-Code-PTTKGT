#include <iostream>
using namespace std;

const int MAX = 100;

// Hàm nhập ma trận
void nhapMaTran(int a[][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Nhap phan tu a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}

// Hàm in ma trận
void inMaTran(int a[][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// Hàm nhân hai ma trận
void nhanMaTran(int a[][MAX], int b[][MAX], int c[][MAX], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int m, n, p;

    cout << "Nhap kich thuoc ma tran A: ";
    cin >> m >> n;

    cout << "Nhap kich thuoc ma tran B: ";
    cin >> n >> p;

    // Nhap ma tran A va B
    cout << "Nhap ma tran A:\n";
    nhapMaTran(a, m, n);

    cout << "Nhap ma tran B:\n";
    nhapMaTran(b, n, p);

    // Tinh toan ma tran tich C
    nhanMaTran(a, b, c, m, n, p);

    // In ket qua
    cout << "Ma tran A:\n";
    inMaTran(a, m, n);

    cout << "Ma tran B:\n";
    inMaTran(b, n, p);

    cout << "Ma tran C:\n";
    inMaTran(c, m, p);

    return 0;
}
