#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;
set<int> coins;

// dp[i] = lượng tờ tiền ít nhất để đổi được đồng có giá trị x sử dụng các
// tờ tiền trong nums
int coinChange(vector<int> &nums, int x) {
    const int n = nums.size();
    vector<int> dp(x + 1, INF);
    // Cần 0 tờ tiền để đổi được tờ có giá trị 0
    dp[0] = 0;
    
    // Mỗi tờ tiền có thể được sử dụng nhiều lần
    for(int i = 1; i <= x; ++i) {
        for(int num : nums) {
            if(i >= num) {
                dp[i] = min(dp[i], 1 + dp[i - num]);
            }
        }
    }

    if(dp[x] == INF) return -1;      // Không đổi được
    // Truy vết: tìm những tờ tiền nào đã được sử dụng
    int i = x;
    while(i > 0) {
        for(int num : nums) {
            if(i >= num && dp[i] == 1 + dp[i - num]) {
                coins.insert(num);
                i -= num;
                break;
            }
        }
    }

    return dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];

    int res = coinChange(nums, x);
    cout << res << endl;

    if(coins.empty()) cout << "Tờ tiền " << x << " không thể đổi được!" << endl;
    else for(int coin : coins) cout << coin << " ";
    
    return 0;
}