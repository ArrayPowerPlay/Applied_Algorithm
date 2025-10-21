// find longest palindrome substring of a string 

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string res;
    int cnt = 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // iterate by substring length
    for(int L = 1; L <= n; ++L) {
        for(int i = 0; i <= n - L; ++i) {
            int j = i + L - 1;
            if(L == 1) dp[i][j] = 1;
            else if(L == 2) dp[i][j] = (s[i] == s[j]);
            else {
                dp[i][j] =  (dp[i + 1][j - 1] == 1) && (s[i] == s[j]);
            }
            if (dp[i][j] == 1 && L > cnt) {
                cnt = L;
                res = s.substr(i, cnt);
            }
        }
    }

    cout << res << endl;
}