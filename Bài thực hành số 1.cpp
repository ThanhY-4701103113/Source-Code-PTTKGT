#include <iostream>
#include <cmath>
using namespace std;

// Ham tinh gia tri cua da thuc tai x bang phuong phap Horner
double horner(double a[], int n, double x) {
    double result = a[n]; // Gan result bang he so bac n cua da thuc
    for (int i = n - 1; i >= 0; i--) {
        result = result * x + a[i]; // Ap dung cong thuc Horner
    }
    return result;
}

int main() {
    int n = 0 ;
    double x;
    cout << "Nhap bac cua da thuc: ";
    cin >> n;

    double a[100];
    cout << "Nhap cac he so cua da thuc: ";
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    cout << "Nhap gia tri x: ";
    cin >> x;

    double result = horner(a, n, x);
    cout << "Gia tri cua da thuc tai x = " << x << " la: " << result << endl;

    return 0;
}