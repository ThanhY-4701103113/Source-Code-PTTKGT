#include<bits/stdc++.h>
using namespace std;

const int N = 1 << 18; // kích thước tối đa của mảng đa thức
int a[N], b[N], c[N]; // các mảng đa thức

void add(int* a, int* b, int n) { // hàm cộng 2 đa thức
    for (int i = 0; i < n; i++) a[i] += b[i];
}

void sub(int* a, int* b, int n) { // hàm trừ 2 đa thức
    for (int i = 0; i < n; i++) a[i] -= b[i];
}

void mul(int* a, int* b, int* c, int n) { // hàm nhân 2 đa thức
    if (n <= 64) { // nếu kích thước đa thức nhỏ hơn 64, ta nhân thường
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                c[i + j] += a[i] * b[j];
        return;
    }
    int m = n / 2; // chia đa thức thành 2 phần
    mul(a, b, c, m); // tính A1*B1
    mul(a + m, b + m, c + n, m); // tính A2*B2
    int t1[N], t2[N];
    for (int i = 0; i < m; i++) t1[i] = a[i] + a[i + m]; // tính A1+A2
    for (int i = 0; i < m; i++) t2[i] = b[i] + b[i + m]; // tính B1+B2
    mul(t1, t2, c + m, m); // tính (A1+A2)*(B1+B2)
    sub(c + m, c, n); // tính (A1+A2)*(B1+B2)-A1*B1-A2*B2
    sub(c + m, c + n, n);
    mul(c + m, t1, t2, m);
    add(c + m, t2, n);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    mul(a, b, c, n);
    for (int i = 0; i < 2 * n - 1; i++) cout << c[i] << " ";
    cout << endl;
    return 0;
}
