#include <iostream>
#include <cstring>
using namespace std;

string longest_common_subsequence(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp)); // Khởi tạo giá trị của bảng DP bằng 0

    // Xây dựng bảng DP
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Truy vết kết quả
    int len = dp[m][n];
    string result(len, ' ');
    int i = m, j = n;
    while (len > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            result[len - 1] = s1[i - 1];
            i--;
            j--;
            len--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    return result;
}

int main() {
    string s1, s2;
    cout << "Nhap chuoi s1: ";
    cin >> s1;
    cout << "Nhap chuoi s2: ";
    cin >> s2;
    string result = longest_common_subsequence(s1, s2);
    cout << "Chuoi chung dai nhat cua " << s1 << " va " << s2 << " la: " << result << endl;
    return 0;
}