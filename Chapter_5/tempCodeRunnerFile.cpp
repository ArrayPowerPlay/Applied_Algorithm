// Given a set of coins with denominations D1, D2, ..., Dn and a denomination x
// Find the minimum number of coins to exchange for denomination x

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> num(n);
    for(int i = 0; i < n; ++i) cin >> num[i];

    int INF = 1e10;
    vector<int> dp(x + 1, INF);
    dp[0] = 0;

    for(int i = 1; i <= x; ++i) {
        for(int coin : num) {
            if(i - coin >= 0 && dp[i - coin] != INF) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if(dp[x] != INF) cout << dp[x] << endl;
    else cout << -1 << endl;
}