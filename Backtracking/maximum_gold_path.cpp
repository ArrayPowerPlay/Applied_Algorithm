#include <bits/stdc++.h>
using namespace std;

// In a gold mine grid of size m x n, each cell in this mine has an integer representing
// the amount of gold in that cell, 0 if it is empty.

// Return the maximum amount of gold you can collect under the conditions:

// Every time you are located in a cell you will collect all the gold in that cell.
// From your position, you can walk one step to the left, right, up, or down.
// You can't visit the same cell more than once.
// Never visit a cell with 0 gold.
// You can start and stop collecting gold from any position in the grid that has some gold.

int globalMaximum = 0;
int localMaximum = 0;
int row[4] = {0, 0, -1, 1};
int col[4] = {1, -1, 0, 0};

void dfs(int r, int c, const int m, const int n, int curr, vector<vector<int>> &visited, vector<vector<int>> &grid) {
    if(curr > localMaximum) localMaximum = curr;
    for(int i = 0; i < 4; ++i) {
        int rr = r + row[i];
        int cc = c + col[i];

        if(rr > m - 1 || rr < 0 || cc > n - 1 || cc < 0 || visited[rr][cc] || grid[rr][cc] == 0) continue;
        visited[rr][cc] = 1;
        dfs(rr, cc, m, n, curr + grid[rr][cc], visited, grid);
        visited[rr][cc] = 0;
    }
}

int getMaximumGold(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(grid[i][j] != 0) {
                for(auto &row : visited) fill(row.begin(), row.end(), 0);
                localMaximum = 0;
                visited[i][j] = 1;
                dfs(i, j, m, n, grid[i][j], visited, grid);
                if(localMaximum > globalMaximum) globalMaximum = localMaximum;
            }
        }
    }

    return globalMaximum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    cout << getMaximumGold(grid) << endl;
}