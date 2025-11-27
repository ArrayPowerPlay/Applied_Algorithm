#include <bits/stdc++.h>
using namespace std;

/*Problem Statement
Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.
The vacation consists of N days. For each i (1≤i≤N), Taro will choose one of the following 
activities and do it on the i-th day:
A: Swim in the sea. Gain a_i points of happiness.
B: Catch bugs in the mountains. Gain b_i points of happiness.
C: Do homework at home. Gain c_i points of happiness.
As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

Find the maximum possible total points of happiness that Taro gains.*/

typedef long long ll;

ll maxPointHappiness(const ll &n, vector<vector<ll>> &points) {
    vector<vector<ll>> dp(n + 1, vector<ll>(4, 0));
    dp[1][1] = points[1][1];
    dp[1][2] = points[1][2];
    dp[1][3] = points[1][3];
    ll best = 0;

    for(int i = 2; i <= n; ++i) {
        for(int k = 1; k <= 3; ++k) {
            for(int j = 1; j <= 3; ++j) {
                if(j == k) continue;
                dp[i][k] = max(dp[i][k], dp[i - 1][j] + points[i][k]);
            }
        }
    }

    for(int j = 1; j <= 3; ++j) {
        best = max(best, dp[n][j]);
    }
    return best;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    vector<vector<ll>> points(n + 1, vector<ll>(4, 0));

    for(int i = 1; i <= n; ++i) {
        cin >> points[i][1] >> points[i][2] >> points[i][3];
    }

    cout << maxPointHappiness(n, points) << endl;


}