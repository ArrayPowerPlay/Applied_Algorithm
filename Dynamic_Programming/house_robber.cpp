/*You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from robbing
each of them is that adjacent houses have security systems connected and it will automatically 
contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum 
amount of money you can rob tonight without alerting the police.*/

#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums) {
    int num_houses = nums.size();
    if(num_houses == 1) return nums[0];

    vector<vector<int>> dp(num_houses, vector<int>(2, 0));
    // dp[i][0]: max sum if not choose i
    // dp[i][1]: max sum if choose i
    dp[0][0] = 0;
    dp[0][1] = nums[0];
    for(int i = 1; i < num_houses; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = nums[i] + dp[i - 1][0];
    }
    return max(dp[num_houses - 1][0], dp[num_houses - 1][1]);
}

// Advanced version
// All houses at this place are arranged in a circle. 
// That means the first house is the neighbor of the last one. 

int robII(vector<int> &nums) {
    int num_houses = nums.size();
    if(num_houses == 1) return nums[0];
    
    vector<int> exclude_first(nums.begin() + 1, nums.end());
    vector<int> exclude_last(nums.begin(), nums.end() - 1);
    return max(rob(exclude_first), rob(exclude_last));
}

int main() {

}