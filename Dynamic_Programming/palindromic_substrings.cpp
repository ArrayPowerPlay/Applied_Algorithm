#include <bits/stdc++.h>
using namespace std;

// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.

int countSubstrings(string s) {
    int n = s.size();
    int res = 0;
    // dp[i][j] = chuỗi con từ chỉ số i tới j có phải chuỗi palindrome hay không
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for(int len = 1; len <= n; ++len) {
        for(int l = 0; l <= n - len; ++l) {
            int r = l + len - 1;
            if(len == 1) dp[l][r] = true;
            else {
                if(len == 2) dp[l][r] = (s[l] == s[r]);
                else {
                    dp[l][r] = ((s[l] == s[r]) && (dp[l + 1][r - 1] == 1));
                }
            }
            if(dp[l][r] == 1) ++res;
        }
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    cout << countSubstrings(s);

}