#include <bits/stdc++.h>
using namespace std;

// Một dãy con là dãy có được bằng cách loại bỏ 1 số phần tử khỏi
// dãy ban đầu. Tìm dãy con dài nhất thỏa mãn s[i] + D <= s[i + 1]
// với i là chỉ số chạy trong dãy

int longestDIncreaseSub(vector<int> &a, const int &n, const int &D) {
    // Độ dài của dãy con tăng dài nhất thỏa mãn mà kết thúc tại 
    // chỉ số i là dp[i]
    vector<int> dp(n + 1, 1);
    dp[1] = 1;
    int res = 1;

    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j < i; ++j) {
            if(a[i] - a[j] >= D) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }

    return res;
}

int main() {
    int n, D;
    cin >> n >> D;
    vector<int> a(n + 1);

    for(int i = 1; i <= n; ++i) cin >> a[i];
    cout << longestDIncreaseSub(a, n, D) << endl;
}