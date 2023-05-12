#include <iostream>
using namespace std;
// Nhập ma trận
void input(int m, int A[][100]);

// In ma trận
void output(int m, int A[][100]);

// Hàm cộng hai ma trận a[][] và b[][] và lưu kết quả vào ma trận c[][]
void add(int n, int a[][100], int b[][100], int c[][100]);

// Hàm trừ hai ma trận a[][] và b[][] và lưu kết quả vào ma trận c[][]
void subtract(int n, int a[][100], int b[][100], int c[][100]);

// Hàm nhân hai ma trận vuông a[][] và b[][] kích thước n và lưu kết quả vào ma trận c[][]
void multiply(int &n, int a[][100], int b[][100], int c[][100]);
int main() {
    int a[100][100], n;
    int b[100][100];
    int c[100][100];
    //Nhập kích thước ma trận
    cin >> n;
    input(n, a);
    input(n, b);
    multiply(n, a, b, c);
    output(n, c);
    return 0;

}
// Nhập ma trận
void input(int m, int A[][100]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
}

// In ma trận
void output(int m, int A[][100]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
// Hàm cộng hai ma trận a[][] và b[][] và lưu kết quả vào ma trận c[][]
void add(int n, int a[][100], int b[][100], int c[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Hàm trừ hai ma trận a[][] và b[][] và lưu kết quả vào ma trận c[][]
void subtract(int n, int a[][100], int b[][100], int c[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

// Hàm nhân hai ma trận vuông a[][] và b[][] kích thước n và lưu kết quả vào ma trận c[][]
void multiply(int &n, int a[][100], int b[][100], int c[][100]) {
    // Nếu chỉ có một phần tử
    if (n == 1) {
        c[0][0] = a[0][0] * b[0][0];
        return;
    }

    // Chia ma trận a và b thành 4 ma trận con
    int m = n / 2;
    int A[100][100], B[100][100], C[100][100], D[100][100];
    int E[100][100], F[100][100], G[100][100], H[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = a[i][j];
            B[i][j] = a[i][m + j];
            C[i][j] = a[i + m][j];
            D[i][j] = a[i + m][j + m];

            E[i][j] = b[i][j];
            F[i][j] = b[i][m + j];
            G[i][j] = b[i + m][j];
            H[i][j] = b[i + m][j + m];
        }
    }
    int tmp[100][100];
    // Tính 7 ma trận P
    int P1[100][100], P2[100][100], P3[100][100], P4[100][100], P5[100][100], P6[100][100], P7[100][100];

    // P1 = A(F - H)
    subtract(m, F, H, P1);
    multiply(m, A, P1, P1);

    // P2 = (A + B)H
    add(m, A, B, P2);
    multiply(m, P2, H, P2);

    // P3 = (C + D)E
    add(m, C, D, P3);
    multiply(m, P3, E, P3);

    // P4 = D(G - E)
    subtract(m, G, E, P4);
    multiply(m, D, P4, P4);
    // P5 = (A + D)(E + H)
    add(m, A, D, P5);

    add(m, E, H, tmp);
    multiply(m, P5, tmp, P5);

    // P6 = (B - D)(G + H)
    subtract(m, B, D, P6);
    add(m, G, H, tmp);
    multiply(m, P6, tmp, P6);

    // P7 = (A - C)(E + F)
    subtract(m, A, C, P7);
    add(m, E, F, tmp);
    multiply(m, P7, tmp, P7);

    // Tính ma trận kết quả
    // Kết quả gán vào ma trận C
    int tmp1[100][100], tmp2[100][100];
    add(m, P5, P4, tmp1);
    subtract(m, tmp1, P2, tmp1);
    add(m, tmp1, P6, tmp1);

    add(m, P1, P2, tmp2);
    add(m, P3, P4, C);
    subtract(m, tmp2, P3, tmp2);
    subtract(m, tmp2, P7, tmp2);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = tmp1[i][j] + tmp2[i][j];
        }
    }
}