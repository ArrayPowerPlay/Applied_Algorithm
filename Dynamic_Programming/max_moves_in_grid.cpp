#include <bits/stdc++.h>
using namespace std;

// You are given a 0-indexed m x n matrix grid consisting of positive integers.
// You can start at any cell in the first column of the matrix, and traverse the grid in the following way:

// From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and
// (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the
// value of the current cell.
// Return the maximum number of moves that you can perform.

int maxMoves(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    // dp[i][j] = số bước đi tối đa để tới vị trí (i, j)
    vector<vector<int>> dp(m, vector<int> (n, -1));
    int res = 0;

    for(int i = 0; i < m; ++i) {
        dp[i][0] = 0;
    }
    
    for(int j = 1; j < n; ++j) {
        for(int i = 0; i < m; ++i) {
            if(i - 1 >= 0 && grid[i][j] > grid[i - 1][j - 1] && dp[i - 1][j - 1] != -1) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            if(grid[i][j] > grid[i][j - 1] && dp[i][j - 1] != -1) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
            }
            if(i < m - 1 && grid[i][j] > grid[i + 1][j - 1] && dp[i + 1][j - 1] != -1) {
                dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1);
            }
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

int main() {

}