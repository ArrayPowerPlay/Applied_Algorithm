#include <bits/stdc++.h>
using namespace std;

/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/

typedef pair<pair<int, int>, int> ppii;

int row[4] = {0, 0, 1, -1};
int col[4] = {1, -1, 0, 0};

int orangesRotting(vector<vector<int>> &grid) {
    // Chúa pair<tọa độ, số bước lan>
    queue<ppii> q;
    int m = grid.size();
    int n = grid[0].size();
    // Số bước lan (tương đương số phút ít nhất để lan)
    int step = 0;
    // Số cam tươi ban đầu
    int fresh_cnt = 0;

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(grid[i][j] == 2) q.push({{i, j}, 0});
            if(grid[i][j] == 1) ++fresh_cnt;
        }
    }

    while(!q.empty()) {
        auto u = q.front();
        int x = u.first.first;
        int y = u.first.second;
        step = u.second;
        q.pop();

        for(int i = 0; i < 4; ++i) {
            int r = x + row[i];
            int c = y + col[i];

            if(r >= 0 && r <= m - 1 && c >= 0 && c <= n - 1) {
                if(grid[r][c] == 2) continue;
                if(grid[r][c] == 1) {
                    grid[r][c] = 2;
                    --fresh_cnt;
                    q.push({{r, c}, step + 1});
                }
            }
        }
    }

    if(fresh_cnt == 0) return step;
    else return -1;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) cin >> grid[i][j];
    }

    cout << orangesRotting(grid) << endl;
}