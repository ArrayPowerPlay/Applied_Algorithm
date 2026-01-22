#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<Point, int>> treasure(n + 1);
    for(int i = 1; i <= n; ++i) {
        Point t;
        int value;
        cin >> t.x >> t.y >> value;
        treasure[i] = {t, value};
    }

    sort(treasure.begin() + 1, treasure.end(), [](const pair<Point, int> &u, const pair<Point, int> &v) {
        Point a = u.first, b = v.first;
        if(a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    vector<long long> dp(n + 1, 0);
    dp[1] = treasure[1].second; 
    long long res = dp[1];

    for(int i = 2; i <= n; ++i) {
        dp[i] = treasure[i].second;
        for(int j = 1; j < i; ++j) {
            Point first = treasure[i].first;
            Point second = treasure[j].first;
            if(first.x >= second.x && first.y >= second.y) {
                dp[i] = max(dp[i], dp[j] + treasure[i].second);
            }
        }
        res = max(res, dp[i]);
    }
    
    cout << res << endl;

}