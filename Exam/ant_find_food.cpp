#include <bits/stdc++.h>
using namespace std;

/*Một cái ống hình trụ được trải phẳng thành một hình chữ nhật kích thước mxn. Một con kiến di chuyển
từ ô bất kỳ ở cột 1 tới ô bất kỳ cột n. Tìm lượng thức ăn lớn nhất mà con kiến có thể thu thập được
(mỗi ô có 1 lượng thức ăn nào đó). Biết do tính chất của hình trụ ban đầu nên khi ở hàng 1, con kiến 
có thể nhảy sang hàng m khi đi lên trên và ngược lại. Từ vị trí [i, j] con kiến có thể di chuyển đến
vị trí [i - 1][j + 1], [i][j + 1], [i + 1][j + 1]*/

int max3(const int a, const int b, const int c) {
    int ab = (a >= b) ? a : b;
    return (ab >= c) ? ab : c;
}

int maxFood(const int &m, const int &n, vector<vector<int>> &maze) {
    // dp[i][j] = lượng thức ăn lớn nhất có thể thu thập được khi di
    // chuyển từ ô bất kỳ từ cột đầu tiên đến ô i cột j
    vector<vector<int>> dp = maze;
    
    for(int j = 2; j <= n; ++j) {
        for(int i = 1; i <= m; ++i) {
            if(i > 1 && i < m) {
                dp[i][j] = max3(dp[i - 1][j - 1], dp[i][j - 1], dp[i + 1][j - 1]) + maze[i][j];
            } else if(i == 1) {
                dp[i][j] = max3(dp[i][j - 1], dp[i + 1][j - 1], dp[m][j - 1]) + maze[i][j];
            } else {
                dp[i][j] = max3(dp[i][j - 1], dp[i - 1][j - 1], dp[1][j - 1]) + maze[i][j];
            }
        }
    }

    int ans = 0;
    for(int k = 1; k <= m; ++k) {
        ans = max(ans, dp[k][n]);
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> maze(m + 1, vector<int>(n + 1, 0));
    
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> maze[i][j];
        }
    }

    int res = 0;
    if(m == 1) {
        for(int i = 1; i <= n; ++i) {
            res += maze[m][i];
            cout << res << endl;
            return 0;
        }
    } else {
        cout << maxFood(m, n, maze) << endl;
        return 0;
    }
}