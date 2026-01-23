#include <bits/stdc++.h>
using namespace std;

// You are given an integer array nums and an integer k. You can partition the array into at most
// k non-empty adjacent subarrays. The score of a partition is the sum of the averages of each subarray.

// Note that the partition must use every integer in nums, and that the score is not necessarily an integer.
// Return the maximum score you can achieve of all the possible partitions.

double largestSumOfAverages(vector<int> &nums, int k) {
    int n = nums.size();
    // prefix sum: prefix[i] = nums[0] + ... + nums[i - 1]
    vector<double> prefix(n + 1, 0.0);
    for(int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + static_cast<double>(nums[i - 1]);
    }
    // dp[i][j] = tổng trung bình lớn nhất khi chia thành j đoạn, đồng thời đã xét các phần tử 0,1,...,i-1
    vector<vector<double>> dp(n + 1, vector<double>(k + 1, 0));
    double res = 0.0;

    for(int j = 1; j <= k; ++j) {
        for(int i = 1; i <= n; ++i) {
            if(i < j) continue;
            if(i == j) dp[i][j] = prefix[i];
            else {
                if(j == 1) dp[i][j] = prefix[i] / i;
                else {
                    for(int t = j - 1; t <= i - 1; ++t) {
                        dp[i][j] = max(dp[i][j], dp[t][j - 1] + (prefix[i] - prefix[t]) / (i - t));
                    }
                }
            }
        }
        res = max(res, dp[n][j]);
    }
    return res;
}

int main() {

}