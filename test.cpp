#include <bits/stdc++.h>
using namespace std;

int maxIncreasingSub(const int &n, vector<int> &a) {
    vector<int> dp(n + 1, 1);
    int ans = 1;
    
    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j < i; ++j) {
            if(a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];

    cout << maxIncreasingSub(n, a) << endl;
}