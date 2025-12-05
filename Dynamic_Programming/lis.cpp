#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums, return the length of the longest strictly increasing subsequence.

/*A subsequence is an array that can be derived from another array by deleting some or no elements
without changing the order of the remaining elements.*/

stack<int> trace;

int longestIncreasingSubsequence(vector<int> &nums) {
    const int n = nums.size();
    // dp[i] = độ dài chuỗi dài nhất mà kết thúc tại chỉ số i
    vector<int> dp(n, 1);
    int ans = 1;
    int best = 0;
    // Chỉ số kết thúc của chuỗi tăng dài nhất
    int maxIndex = 0;

    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if(ans < dp[i]) {
            ans = dp[i];
            maxIndex = i;
        }
    }

    // Truy vết: Tìm các phần tử của dãy con tăng dài nhất
    int i = maxIndex;
    trace.push(nums[maxIndex]);

    while(i > 0) {
        bool found = false;
        for(int j = i - 1; j >= 0; --j) {
            if(nums[j] < nums[i] && dp[j] + 1 == dp[i]) {
                trace.push(nums[j]);
                i = j;
                found = true;
                break;
            }
        }
        // Không tìm thấy phần tử trước đó thỏa mãn -> dừng để tránh lặp vô hạn
        if(!found) break;
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
    while(!trace.empty()) {
        int t = trace.top();
        trace.pop();
        cout << t << " ";
    }
}
