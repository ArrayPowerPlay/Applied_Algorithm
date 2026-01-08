// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), 
// ans[i] is the number of 1's in the binary representation of i.
#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n) {
    if(n == 0) return {0};
    if(n == 1) return {0, 1};
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 1; i <= n; ++i) {
        if(i % 2 == 0) dp[i] = dp[i >> 1];
        else dp[i] = dp[i >> 1] + 1;
    }
    return dp;
}

int main() {

}