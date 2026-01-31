#include <bits/stdc++.h>
using namespace std;

// Longest Palindromic Subsequence (LPS)
/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by 
deleting some or no elements without changing the order of the remaining elements.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    // dp[i][j] = độ dài LPS trong đoạn s[i...j]
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int res = 0;

    for(int i = n - 1; i >= 0; --i) {
        for(int j = i; j < n; ++j) {
            if(i == j) dp[i][j] = 1;
            else if(s[i] == s[j]) dp[i][j] = 2 + dp[i + 1][j - 1];
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            res = max(res, dp[i][j]);
        }
    }
    cout << res << endl;
} 