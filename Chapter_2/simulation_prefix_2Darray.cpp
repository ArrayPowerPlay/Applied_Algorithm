#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q, r1, r2, c1, c2;
    cin >> n >> m;
    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    vector<vector<int>> prefix_sum(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + arr[i][j];
        }
    }

    cin >> q;
    for(int k = 0; k < q; ++k) {
        cin >> r1 >> c1 >> r2 >> c2;
        cout << prefix_sum[r2][c2] - prefix_sum[r2][c1 - 1] - prefix_sum[r1 - 1][c2] + prefix_sum[r1 - 1][c1 - 1] << endl;
    }
}