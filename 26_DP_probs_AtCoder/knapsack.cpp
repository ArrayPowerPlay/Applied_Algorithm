#include <bits/stdc++.h>
using namespace std;

/*Problem Statement 
There are N items, numbered 1,2,…,N. For each i (1≤i≤N), Item i has a weight of 
w_i and a value of v_i. Taro has decided to choose some of the N items and carry
them home in a knapsack. The capacity of the knapsack is W, which means that the
sum of the weights of items taken must be at most W.

Find the maximum possible sum of the values of items that Taro takes home.*/

typedef long long ll;

/*Constraints:
1 ≤ N ≤ 100
1 ≤ W ≤ 10^5
1 ≤ w_i ≤ W
1 ≤ v_i ≤ 10^9*/

ll knapsack1(const ll &n, const ll &W, vector<ll> &w, vector<ll> &v) {
    // dp[i][j] = tổng giá trị lớn nhất khi xét chọn i item đầu tiên, 
    // đồng thời tổng khối lượng không vượt quá j
    vector<vector<ll>> dp(n + 1, vector<ll>(W + 1, 0));
    dp[1][w[1]] = v[1];
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= W; ++j) {
            dp[i][j] = dp[i - 1][j];              // không chọn item i
            if(j >= w[i]) {                       // chọn item i
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    return dp[n][W];
}

/*All values in input are integers.
1 ≤ N ≤ 100
1 ≤ W ≤ 10^9
1 ≤ w_i ≤ W
1 ≤ v_i ≤ 10^3*/

const ll INF = 1e18;

ll knapsack2(const ll &n, const ll &W, vector<ll> &w, vector<ll> &v) {
    // Do constraint của bài toán ta sẽ đặt DP theo điều kiện sau:
    // dp[val] = Lượng cân nặng nhỏ nhất để đặt được tổng giá trị = val
    // Ta cần tìm val lớn nhất sao cho dp[val] <= W
    ll val = 0;
    for(int i = 1; i <= n; ++i) val += v[i];

    vector<ll> dp(val + 1, INF);
    ll best = 0;
    dp[0] = 0;
    
    // hướng tiếp cận topdown
    for(int i = 1; i <= n; ++i) {
        for(int j = val; j >= v[i]; --j) {
            dp[j] = min(dp[j], w[i] + dp[j - v[i]]);
            if(dp[j] <= W && best < j) best = j; 
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, W;
    cin >> n >> W;
    vector<ll> w(n + 1);
    vector<ll> v(n + 1);

    for(int i = 1; i <= n; ++i) cin >> w[i] >> v[i];
    cout << knapsack2(n, W, w, v) << endl;
    
}