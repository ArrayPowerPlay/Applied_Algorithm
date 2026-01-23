#include <bits/stdc++.h>
using namespace std;

// Given the integers zero, one, low, and high, we can construct a string by starting with an 
// empty string, and then at each step perform either of the following:

// Append the character '0' zero times.
// Append the character '1' one times.
// This can be performed any number of times.
// A good string is a string constructed by the above process having a length between low and high (inclusive).

// Return the number of different good strings that can be constructed satisfying these properties. Since the
// answer can be large, return it modulo 109 + 7.

const int MOD = 1e9 + 7;
typedef long long ll;
ll countGoodStrings(int low, int high, int zero, int one) {
    // dp[i] = số cách tạo chuỗi có độ dài i thỏa mãn đề ra
    vector<ll> dp(high + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= high; ++i) {
        if(i >= zero && i >= one) {
            dp[i] = (dp[i - one] + dp[i - zero]) % MOD;
        } else if(i >= zero) {
            dp[i] = dp[i - zero];
        } else if(i >= one) {
            dp[i] = dp[i - one];
        }
    }
    ll res = 0;
    for(int i = low; i <= high; ++i) {
        res += (dp[i] % MOD);
    }
    return res % MOD;

}

int main() {
    int low, high, zero, one;
    cin >> low >> high >> zero >> one;
    cout << countGoodStrings(low, high, zero, one);
}