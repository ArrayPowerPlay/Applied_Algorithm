#include <bits/stdc++.h>
using namespace std;

// Tìm độ dài đường đi dài nhất từ điểm [xs, ys] tới điểm [xt, yt] trong ma trận m x n
// Có thể di chuyển theo cả 4 hướng: trên, dưới, trái, phải
// Ô 1 tức là có thể di chuyển được, ô 0 là chướng ngại vật

int m, n;
int xs, ys, xt, yt;
const int INF = 1e9;
vector<vector<int>> maze;
vector<vector<int>> visited;
vector<int> row = {1, 0, 0, -1};
vector<int> col = {0, 1, -1, 0};
int currPath = 0;
int maxPath = -INF;

void Try(int x, int y) {
    for(int i = 0; i < 4; ++i) {
        int xx = x + row[i];
        int yy = y + col[i];

        if(xx == 0 || xx == m + 1 || yy == 0 || yy == n + 1 || maze[xx][yy] == 0 || visited[xx][yy]) continue;

        ++currPath;
        visited[xx][yy] = 1;

        if(xx == xt && yy == yt) {
            maxPath = max(maxPath, currPath);
        } else {
            Try(xx, yy);
        }

        visited[xx][yy] = 0;
        --currPath;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n;
    cin >> xs >> ys >> xt >> yt;
    maze.resize(m + 1, vector<int>(n + 1));
    visited.assign(m + 1, vector<int>(n + 1, 0));
    visited[xs][ys] = 1;

    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> maze[i][j];
        }
    }

    Try(xs, ys);
    cout << maxPath << endl;
}