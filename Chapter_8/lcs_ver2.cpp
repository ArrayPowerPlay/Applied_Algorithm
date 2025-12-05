#include <bits/stdc++.h>
using namespace std;

// Giống LCS nhưng thay vì tìm dãy con chung dài nhất của 2 chuỗi thì ta tìm
// trên 2 vector số nguyên

pair<int, vector<int>> longestCommonSub(vector<int> &a, vector<int> &b) {
    int m = a.size();
    int n = b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for(int i = m - 1; i >= 0; --i) {
        for(int j = n - 1; j >= 0; --j) {
            if(a[i] == b[j]) {
                dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j + 1]);
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    // Truy vết
    vector<int> vec;
    int i = 0, j = 0;
    while(i < m && j < n) {
        if(a[i] == b[j]) {
            vec.push_back(a[i]);
            ++i;
            ++j;
        } else {
            if(dp[i + 1][j] >= dp[i][j + 1]) {
                ++i;
            } else {
                ++j;
            }
        }
    }

    return {dp[0][0], vec};
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> a(m);
    vector<int> b(n);

    for(int i = 0; i < m; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    auto e = longestCommonSub(a, b);
    cout << e.first << endl;

    // Phục vụ truy vết
    for(int t : e.second) {
        cout << t << " ";
    }
}