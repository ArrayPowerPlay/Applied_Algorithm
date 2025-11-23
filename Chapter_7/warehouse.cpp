#include <bits/stdc++.h>
using namespace std;

/*Có n nhà kho nằm trên 1 đường thẳng. Nhà kho i chứa lượng hàng a_i, thời gian 
lấy hàng t_i và nằm ở vị trí i. Tìm 1 chiến lược lấy hàng sao cho:
- 2 nhà kho được lấy hàng liên tiếp nhau có khoảng cách <= D
- Tổng thời gian lấy hàng <= T
- Tối đa hóa lượng hàng lấy được

Output: Lượng hàng tối đa lấy được*/

int maxLoad(const int &n, const int &D, const int &T, vector<int> &a, vector<int> &t) {
    // dp[i][k] = Lượng hàng tối đa lấy được nếu xét các kho từ 1 đến i - 1, lấy kho i
    // và lượng hàng lấy được không vượt quá k
    // i chạy từ 1 đến n
    // k chạy từ 1 đến T
    vector<vector<int>> dp(n + 1, vector<int>(T + 1, 0));
    dp[1][t[1]] = a[1];
    int best = a[1];

    for(int i = 1; i <= n; ++i) {
        for(int k = 1; k <= T; ++k) {
            if(k < t[i]) {
                dp[i][k] = 0;
            } else {
                for(int j = 1; j <= D && j <= i; ++j) {
                    dp[i][k] = max(dp[i][k], a[i] + dp[i - j][k - t[i]]);
                    best = max(best, dp[i][k]);
                }
            }
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, T, D;
    cin >> n >> T >> D;
    vector<int> a(n + 1);
    vector<int> t(n + 1);

    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> t[i];

    cout << maxLoad(n, D, T, a, t) << endl;
}