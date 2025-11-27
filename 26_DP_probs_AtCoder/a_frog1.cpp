#include <bits/stdc++.h>
using namespace std;

// Problem statement:

/*There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone 
i is h_i. There is a frog who is initially on Stone 1. He will repeat the following
action some number of times to reach Stone N:

If the frog is currently on Stone i, jump to Stone i+1 or Stone i+2. Here, a cost of 
∣h_i−h_j∣ is incurred, where j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches Stone N.*/

typedef long long ll;
const ll INF = 1e18;

ll minCostFrog(const int &n, vector<ll> &h) {
    if(n == 1) return 0;
    // dp[i] = minimum possible total cost to reach Stone i
    vector<ll> dp(n + 1, INF);
    dp[1] = 0;
    
    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j <= 2 && j < i; ++j) {
            dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
        }
    }
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    vector<ll> h(n + 1);
    for(int i = 1; i <= n; ++i) cin >> h[i];

    cout << minCostFrog(n, h) << endl;
}