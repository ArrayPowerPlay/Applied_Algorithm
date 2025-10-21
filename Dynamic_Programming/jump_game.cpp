// You are given an integer array nums
// You are initially positioned at the array's first index
// and each element in the array represents your maximum jump length at that position
// Return true if you can reach the last index, or false otherwise.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int farthest = 0, cur_end = 0;
    vector<int> arr(n);

    for(int i = 0; i < n; ++i) cin >> arr[i];

    if(n <= 1) return true;
    for(int i = 0; i < n; ++i) {
        farthest = max(farthest, i + arr[i]);
        if (i == cur_end) {
            cur_end = farthest;
            if(cur_end >= n - 1) break;
        }
    }

    bool res = (cur_end >= n - 1) ? true : false;
    cout << res << endl;
}

