#include<bits/stdc++.h>
using namespace std;
void Balo1(int n, int W, int F[][100], int w[], int v[]) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                F[i][j] = 0;
            }
            else if (w[i - 1] <= j) {
                F[i][j] = max(F[i - 1][j], v[i - 1] + F[i - 1][j - w[i - 1]]);
            }
            else {
                F[i][j] = F[i - 1][j];
            }
        }
    }
    cout << F[n][W] << endl;
}
int main() {
    int W, n;
    cin >> W >> n;
    int w[n], v[n];
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    int F[n + 1][100];

    Balo1(n, W, F, w, v);
    return 0;
}
