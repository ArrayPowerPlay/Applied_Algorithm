// Given an array of intervals intervals where intervals[i] = [starti, endi], 
// return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
#include <bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    int n = intervals.size();
    if(n == 1) return 0;
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
        if(a[0] != b[0]) return a[0] < b[0];
        else return a[1] < b[1];
    });

    int last = intervals[0][1];
    int res = 0;

    for(int i = 1; i < n; ++i) {
        vector<int> v = intervals[i];
        if(v[0] < last) {
            ++res;
            if(v[1] < last) last = v[1];
        } else {
            last = v[1];
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}



