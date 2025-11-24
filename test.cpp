#include <bits/stdc++.h>
using namespace std;

vector<int> row = {-1, 0, 1, 0};
vector<int> col = {0, 1, 0, -1};

int shortestStepsBFS(vector<vector<int>> &maze, vector<vector<int>> &visited, const int &r, const int &c)
{
    queue<tuple<int, int, int>> q;
    q.push({r, c, 1});
    visited[r][c] = 1;

    int n = maze.size() - 1;
    int m = maze[0].size() - 1;

    while (!q.empty())
    {
        auto [rr, cc, d] = q.front();
        q.pop();
        if (rr == n || cc == m || rr == 1 || cc == 1)
        {
            return d;
        }

        for (int i = 0; i < 4; ++i)
        {
            int next_r = rr + row[i];
            int next_c = cc + col[i];
            if(next_r < 1 && next_r > n && next_c < 1 && next_c > m) continue; 
            if (maze[next_r][next_c] == 0 && !visited[next_r][next_c])
            {
                q.push({next_r, next_c, d + 1});
                visited[next_r][next_c] = 1;
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, r, c;
    cin >> n >> m >> r >> c;

    vector<vector<int>> maze(n + 1, vector<int>(m + 1));
    vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> maze[i][j];
        }
    }

    cout << shortestStepsBFS(maze, visited, r, c) << endl;
}
