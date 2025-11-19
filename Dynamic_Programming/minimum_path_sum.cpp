#include <bits/stdc++.h>
using namespace std;

/*Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.*/

int minPathSum(vector<vector<int>> &grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    // dp[i][j] = min path sum to row i col j
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i == 0 && j == 0) dp[i][j] = grid[0][0];
            else if(i == 0) {
                dp[i][j] = dp[i][j - 1] + grid[i][j];
            } else if(j == 0) {
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            } else {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }
    }

    return dp[m - 1][n - 1];
}

int main() {

}