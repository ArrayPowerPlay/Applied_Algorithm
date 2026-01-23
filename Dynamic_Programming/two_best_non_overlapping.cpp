#include <bits/stdc++.h>
using namespace std;

// You are given a 0-indexed 2D integer array of events where events[i] = [startTime_i, endTime_i, value_i]. 
// The ith event starts at startTime_i and ends at endTime_i, and if you attend this event, you will receive
// a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their
// values is maximized.

// Return this maximum sum.
// Note that the start time and end time is inclusive

int maxTwoEvents(vector<vector<int>> &events) {
    int n = events.size();

    // Sort theo thời gian kết thúc
    sort(events.begin(), events.end(), [](auto &a, auto &b) {
        if(a[1] != b[1]) return a[1] < b[1];
        return a[0] < b[0];
    });

    // best[i] = Giá trị value tốt nhất của các event từ chỉ số 0 tới i
    vector<int> best(n, 0);
    for(int i = 0; i < n; ++i) {
        if(i == 0) best[i] = events[0][2];
        else best[i] = max(events[i][2], best[i - 1]);
    }

    int res = best[0];
    for(int i = 1; i < n; ++i) {
        // Tìm j lớn nhất sao cho events[j][1] < events[i][0]
        // Tìm theo binary search
        int j = -1;
        int lo = 0, hi = i - 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(events[mid][1] < events[i][0]) {
                j = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }   
        int plus = 0;
        if(j != -1) plus = best[j]; 
        res = max({
            res,
            events[i][2],             // chọn 1 events 
            events[i][2] + plus       // chọn 2 events
        });
    }
    return res;
    
}

int main() {

}