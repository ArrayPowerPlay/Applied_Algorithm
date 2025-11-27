#include <bits/stdc++.h>
using namespace std;

/*Problem Statement
You are given strings s and t. Find one longest string that is a subsequence of both 
s and t.*/

/*Constraints:
s and t are strings consisting of lowercase English letters.
1 ≤ ∣s∣, ∣t∣ ≤ 3000*/

pair<int, string> longestCommonSubsequence(const string &s, const string &t) {
    int m = s.size();
    int n = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for(int i = m - 1; i >= 0; --i) {
        for(int j = n - 1; j >= 0; --j) {
            if(s[i] == t[j]) {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    int i = 0, j = 0;
    string res;
    while(i < m && j < n) {
        if(s[i] == t[j]) {
            res += s[i];
            ++i;
            ++j;
        } else if(dp[i + 1][j] >= dp[i][j + 1]) 
            ++i;
        else ++j;
    }

    return {dp[0][0], res};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, t;
    cin >> s >> t;
    auto res = longestCommonSubsequence(s, t);
    cout << res.first << endl;
    cout << res.second << endl; 
}