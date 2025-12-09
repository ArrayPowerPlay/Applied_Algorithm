#include <bits/stdc++.h>
using namespace std;

/*Đếm số đường đi từ vị trí (1, 1) tới vị trí (h, w) mà chỉ được di chuyển
sang phải hoặc xuống dưới. Ô '.' trong ma trận tức là ô trống, ô '#' là 
chướng ngại vật*/

int countPaths(const int &h, const int &w, vector<vector<int>> &maze) {
    vector<vector<int>> dp = maze;

    for(int i = 1; i <= h; ++i) {
        for(int j = 1; j <= w; ++j) {
            if(maze[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            }
            if(i == 1) {
                if(j == 1) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = ((maze[i][j - 1] == 0) ? dp[i][j - 1] : 0) % (int)(1e9 + 7);
            } else if(j == 1) {
                dp[i][j] = ((maze[i - 1][j] == 0) ? dp[i - 1][j] : 0) % (int)(1e9 + 7);
            } else {
                int first = ((maze[i - 1][j] == 0) ? dp[i - 1][j] : 0);
                int second = ((maze[i][j - 1] == 0) ? dp[i][j - 1] : 0);
                dp[i][j] = (first + second) % (int)(1e9 + 7);
            }
        }
    }

    return dp[h][w];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int h, w;
    cin >> h >> w;
    vector<vector<int>> maze(h + 1, vector<int>(w + 1));

    string s;
    for(int i = 1; i <= h; ++i) {
        cin >> s;
        char c;
        for(int j = 1; j <= w; ++j) {
            char c = s[j - 1];
            if(c == '.') maze[i][j] = 0;
            else maze[i][j] = 1;
        }
    }

    cout << countPaths(h, w, maze) << endl;
}