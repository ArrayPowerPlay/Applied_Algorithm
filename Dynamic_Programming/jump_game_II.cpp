// You are given a 0-indexed array of integers nums of length n
// You are initially positioned at index 0
// Return the minimum number of jumps to reach index n - 1 
// The test cases are generated such that you can reach index n - 1.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int cur_end = 0, farthest = 0;
    int res = 0;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; ++i) cin >> arr[i];

    if(n == 1) return 0;
    for(int i = 0; i < n; ++i) {
        farthest = max(farthest, i + arr[i]);
        if (i == cur_end) {
            ++res;
            cur_end = farthest;
            if(cur_end >= n - 1) break;
        }
    }

    cout << res << endl;
}