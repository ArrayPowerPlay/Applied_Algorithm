#include <bits/stdc++.h>
using namespace std;

// You are given a positive integer n, you can do the following operation any number of times:

// Add or subtract a power of 2 from n.
// Return the minimum number of operations to make n equal to 0.

// A number x is power of 2 if x == 2i where i >= 0.

// Check if n is power of 2
int checkPower(int n) {
    while(n != 1) {
        if(n % 2 == 0) n /= 2;
        else return 0;
    }
    return 1;
}

int minOperations(int n) {
    if(n == 1 || n == 2) return 1;
    if(checkPower(n)) return 1;
    // dp[i] = số cách ít nhất để tạo nên i từ cách đề bài cho
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i <= n; ++i) {
        if(checkPower(i)) dp[i] = 1;
        else {
            int i1 = 1;
            while(i1 < i) {
                i1 = i1 * 2;
            }
            int i2 = i1 / 2;
            dp[i] = min(dp[i1 - i], dp[i - i2]) + 1;
        }
    }
    return dp[n];
}

int main() {

}