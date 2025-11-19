#include <bits/stdc++.h>
using namespace std;

// Solution 1: using DP
int max_even_subsequence(vector<int> &nums) {
    int best = 0;
    const int n = nums.size();
    // Max even subsequence that ends in index i
    vector<int> dp(n, 0);
    dp[0] = (nums[0] % 2 == 0 && nums[0] > 0) ? nums[0] : 0;
    best = max(best, dp[0]);

    for(int i = 1; i < n; ++i) {
        if(nums[i] % 2 == 1) {
            dp[i] = 0;
        } else {
            dp[i] = max(dp[i - 1] + nums[i], max(0, nums[i]));
        }
        best = max(best, dp[i]);
    }

    return best;
    
}

// Solution 2: using simple logic strategy
int max_even_subsequence2(vector<int> &nums) {
    const int n = nums.size();
    int res = 0, curr = 0;

    for(int num : nums) {
        if(num % 2 == 0) {
            curr = max(curr, curr + num);
        } else {
            curr = 0;
        }
        res = max(res, curr);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i = 0; i < n; ++i) cin >> nums[i];

    cout << max_even_subsequence(nums) << endl;
    cout << max_even_subsequence2(nums) << endl;
}