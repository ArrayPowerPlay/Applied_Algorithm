/*You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer
in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build
the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: using backtracking
vector<int> choices = {-1, 1};
int res = 0;

void Try(int k, int currSum, vector<int> &nums, const int &target) {
    if(k == nums.size() && currSum == target) {
        ++res;
        return;
    }

    for(int i : choices) {
        currSum += nums[k] * i;
     
        Try(k + 1, currSum, nums, target);
        
        // Backtrack
        currSum -= nums[k] * i;
    }
}

int findTargetSumWays(vector<int> &nums, int target) {
    Try(0, 0, nums, target);
    return res;
}

// Solution 2: using DP
int findTargetSumWaysDP(vector<int> &nums, int target) {
    int len = nums.size();
    // We have positive elements of vector 'nums'
    // After adding +-, we have Sum(P) - Sum(N) should be equals to 'target'
    // We have Sum(P) + Sum(N) = total
    // Which means Sum(P) = (total + target) / 2
    // Problem equivalents to: count number of subsets in 'nums' that have
    // sum equals to 'target'
    int total = accumulate(nums.begin(), nums.end(), 0);
    // Cannot find a solution
    if(total < abs(target) || (total + target) % 2 == 1) return 0;
    int S = (total + target) / 2;
    // We build dp[i] = number of subsets that sum up to i from a given prefix
    vector<int> dp(S + 1, 0);
    dp[0] = 1;

    for(int num : nums) {
        for(int j = S; j >= num; --j) {
            dp[j] += dp[j - num];
        }
    }
    return dp[S];
}

int main() {

}