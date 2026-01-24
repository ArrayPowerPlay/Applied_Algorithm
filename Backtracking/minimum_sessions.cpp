#include <bits/stdc++.h>
using namespace std;

// There are n tasks assigned to you. The task times are represented as an integer array tasks
// of length n, where the ith task takes tasks[i] hours to finish. A work session is when you
// work for at most sessionTime consecutive hours and then take a break.

// You should finish the given tasks in a way that satisfies the following conditions:

// If you start a task in a work session, you must complete it in the same work session.
// You can start a new task immediately after finishing the previous one.
// You may complete the tasks in any order.
// Given tasks and sessionTime, return the minimum number of work sessions needed to finish 
// all the tasks following the conditions above.

int minSessions(vector<int> &tasks, int sessionTime) {
    int n = tasks.size();
    int N = 1 << n;
    // dp[mask] = {số session để các công việc hoàn thành đạt trạng thái mask, thời gian còn
    //             lại trong session đó}
    vector<pair<int, int>> dp(N, {n + 1, 0});
    dp[0] = {1, sessionTime};

    for(int mask = 0; mask < N; ++mask) {
        if(dp[mask].first == n + 1) continue;       // mask này chưa đạt được nên không được
                                                    // chuyển trạng thái từ nó
        for(int i = 0; i < n; ++i) {
            if(mask & (1 << i)) continue;

            int newMask = mask | (1 << i);
            pair<int, int> nxt;
            pair<int, int> curr = dp[mask];

            if(curr.second >= tasks[i]) {
                nxt = {curr.first, curr.second - tasks[i]};
            } else {
                nxt = {curr.first + 1, sessionTime - tasks[i]};
            }

            if(nxt.first < dp[newMask].first || 
                (nxt.first == dp[newMask].first && nxt.second >= dp[newMask].second)) {
                dp[newMask] = nxt;
            }
        }
    }
    return dp[N - 1].first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, sessionTime;
    cin >> n >> sessionTime; 
    vector<int> tasks(n);
    
    for(int i = 0; i < n; ++i) cin >> tasks[i];

    cout << minSessions(tasks, sessionTime) << endl;
}