// given a maze matrix with 0 -> can be accessed, 1 -> wall
// start from a blank space in the matrix (value 0)
// find the shortest path to get out of the maze
// output: the length of the shortest path
// or -1 if can find the way out

#include <bits/stdc++.h>
using namespace std;

// idea: BFS using queue to find shortest path

int main() {
    // r: starting row, c: starting col
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    vector<vector<int>> maze(n + 1, vector<int>(m + 1));
    // matrix save shortest distance from a 0-element subsquare to the starting subsquare
    vector<vector<int>> dist(n + 1, vector<int>(m + 1));

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> maze[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({r, c});

    maze[r][c] = 1;
    dist[r][c] = 0;

    while(!q.empty()) {
        auto num = q.front();
        q.pop();

        for(int i = 0; i < 4; ++i) {
            int x = num.first + dx[i];
            int y = num.second + dy[i];

            if(x == 0 || x == n + 1 || y == 0 || y == m + 1) {
                cout << dist[num.first][num.second] + 1 << endl;
                return 0;
            }

            if(maze[x][y] == 0) {
                dist[x][y] = dist[num.first][num.second] + 1;
                maze[num.first][num.second] = 1;
                q.push({x, y});
            }
        }
    }

    cout << -1 << endl;
}