// Calculate the sum of the smallest numbers in the sub-segments of a given segment
// RMQ problem 

#include <bits/stdc++.h>
using namespace std;

int rmq(int i, int j, vector<int>& arr, vector<vector<int>>& M) {
    int k = log2(j - i + 1);

    if(arr[M[k][i]] < arr[M[k][j - (1 << k) + 1]]) {
        return M[k][i];
    } else {
        return M[k][j - (1 << k) + 1];
    }
}

int main() {
    int n, m, i, j, res = 0;
    cin >> n;
    int k = log2(n) + 1;
    vector<int> arr(n);
    // M[i][j] is the index of the smallest element in the sub-segments start from arr[j]
    // and have a size of exactly 2^i
    vector<vector<int>> M(k, vector<int>(n));

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        M[0][i] = i;
    }

    for(int i = 1; (1 << i) <= n; ++i) {
        for(int j = 0; j + (1 << i) - 1 < n; ++j) {
            if(arr[M[i-1][j]] < arr[M[i - 1][j + (1 << (i - 1))]]) {
                M[i][j] = M[i - 1][j];
            } else {
                M[i][j] = M[i - 1][j + (1 << (i - 1))];
            }
        }
    }

    cin >> m;

    for(int t = 0; t < m; ++t) {
        cin >> i >> j;
        res += arr[rmq(i, j, arr, M)];
    }

    cout << res << endl;
}