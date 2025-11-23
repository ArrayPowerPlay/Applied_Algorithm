#include <bits/stdc++.h>
using namespace std;

// Có n nhà kho chứa vàng cùng nằm trên một đường thẳng. Nhà kho i có lượng vàng
// là a_i và nằm ở vị trí i. Tìm một tập các nhà kho có tổng lượng vàng lớn nhất.

// Constraint: Khoảng cách giữa 2 nhà kho liền kề phải nằm trong [L1, L2]
// Output: Tổng lượng vàng tìm được 

// Solution using DP
int goldMining(const int &n, vector<int> &nums, const int &L1, const int &L2) {
    // Edge cases
    if(n == 0) return 0;
    if(n == 1) return nums[0]; 
    // dp[i] = tổng lượng vàng tìm được nếu nhà kho cuối cùng kết thúc tại vị trí i
    vector<int> dp(nums.begin(), nums.end());
    int best = dp[0];
    
    for(int i = 1; i < n; ++i) {
        for(int c = L1; c <= L2; ++c) {
            if(i < c) break;
            dp[i] = max(dp[i], nums[i] + dp[i - c]);
        }
        best = max(best, dp[i]);
    }

    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, L1, L2;
    cin >> n >> L1 >> L2;
    vector<int> a(n);

    for(int i = 0; i < n; ++i) cin >> a[i];

    cout << goldMining(n, a, L1, L2) << endl;
}