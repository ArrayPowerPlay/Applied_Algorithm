#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums, find the subarray with the largest sum, and return its sum.
/*
Input: nums = [-1]
Output: -1
*/

stack<int> st;

// Solution using DP
int maxSubArray(vector<int> &nums) {
    const int n = nums.size();
    // dp[i] = largest sum of subarray that terminates at index i
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    int best = dp[0];
    // Chỉ số kết thúc của dãy con có tổng lớn nhất, phục vụ cho việc truy vết
    int end_idx = 0;

    for(int i = 1; i < n; ++i) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        if(best < dp[i]) {
            best = dp[i];
            end_idx = i;
        }
    }

    // Truy vết, lưu các phần tử của dãy con có tổng lớn nhất
    int i = end_idx;
    st.push(nums[i]);
    // Lùi lại cho đến khi không còn kéo dài được dãy con tối ưu
    while(i > 0 && dp[i] == dp[i - 1] + nums[i]) {
        --i;
        st.push(nums[i]);
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

    while(!st.empty()) {
        int x = st.top();
        cout << x << " ";
        st.pop();
    }
}
