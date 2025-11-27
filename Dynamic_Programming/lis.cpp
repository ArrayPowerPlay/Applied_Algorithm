#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums, return the length of the longest strictly increasing subsequence.

/*A subsequence is an array that can be derived from another array by deleting some or no elements
without changing the order of the remaining elements.*/

int longestIncreasingSubsequence(vector<int> &nums) {
    const int n = nums.size();
    // dp[i] = độ dài chuỗi dài nhất mà kết thúc tại chỉ số i
    vector<int> dp(n, 1);
    dp[0] = 1;
    int ans = dp[0];
    int best = 0;

    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(nums[j] < nums[i]) {
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
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];

    cout << longestIncreasingSubsequence(nums) << endl;
}