#include <bits/stdc++.h>
using namespace std;

// You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

// Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. 
// At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) 
// which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are
// no more elements in the array.

// Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and
// you should also return true. You may assume that both players are playing optimally.

bool predictTheWinner(vector<int> &nums) {
    int n = nums.size();
    const int INF = 1e9;
    // dp[l][r] = khoảng cách lớn nhất giữa người chơi hiện tại và người chơi còn lại khi chỉ còn đoạn nums[l...r]
    vector<vector<int>> dp(n, vector<int>(n, -INF));
    // Ta tính dp theo độ dài từ 1 đến n
    for(int len = 1; len <= n; ++len) {
        for(int l = 0; l <= n - len; ++l) {
            int r = l + len - 1;
            if(len == 1) dp[l][r] = nums[l];
            else {
                dp[l][r] = max(
                    nums[l] - dp[l + 1][r], 
                    nums[r] - dp[l][r - 1]
                );
            }
        }
    }
    return dp[0][n - 1] >= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}