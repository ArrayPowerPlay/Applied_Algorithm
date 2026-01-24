#include <bits/stdc++.h>
using namespace std;

// Suppose you have n integers labeled 1 through n. A permutation of those n integers
// perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), 
// either of the following is true:

// perm[i] is divisible by i.
// i is divisible by perm[i].
// Given an integer n, return the number of the beautiful arrangements that you can construct.

int cnt = 0;

void dfs(int k, int n, vector<int> &visited) {
    if(k == n + 1) {
        ++cnt;
        return;
    }

    for(int v = 1; v <= n; ++v) {
        if (visited[v]) continue;
        if (v % k != 0 && k % v != 0) continue;
        visited[v] = 1;
        dfs(k + 1, n, visited);
        visited[v] = 0;
    }
}

int countArrangement(int n) {
    vector<int> visited(n + 1, 0);
    dfs(1, n, visited);
    return cnt;
}

int countArrangementDP(int n) {
    // Ta áp dụng bitmask với bit thứ i được đánh dấu là 0 (từ phải sang) tức là i đã được sử
    // dụng trong arrangement hiện tại
    // mask đánh dấu các phần tử đã được sử dụng
    int N = 1 << n;
    // dp[mask] = số cách sắp xếp hợp lý để có được trạng thái mask
    vector<int> dp(N, 0);
    dp[0] = 0;

    for(int mask = 0; mask < N; ++mask) {
        // Chỉ số đang xét hiện tại (tính từ 1 đến n)
        int k = __builtin_popcount(mask) + 1;
        for(int v = 1; v <= n; ++v) {
            if(mask & (1 << (v - 1))) continue;
            if(k % v == 0 || v % k == 0) {
                dp[mask | (1 << (v - 1))] += dp[mask];
            }
        }
    }

    return dp[N - 1];
}

int main() {

}