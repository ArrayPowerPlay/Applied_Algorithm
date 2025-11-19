#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums, find the subarray with the largest sum, and return its sum.
/*
Input: nums = [-1]
Output: -1
*/

// Solution using DP
int maxSubArray(vector<int> &nums) {
    const int n = nums.size();
    // dp[i] = largest sum of subarray that terminates at index i
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    int best = dp[0];

    for(int i = 1; i < n; ++i) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        best = max(best, dp[i]);
    }

    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i = 0; i < n; ++i) cin >> nums[i];

    cout << maxSubArray(nums) << endl;
}