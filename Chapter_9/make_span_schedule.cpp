#include <bits/stdc++.h>
using namespace std;

/*Lập lịch cho 1 project có nhiều tác vụ:
Một project có n tác vụ: 1, 2,..., n
- Tác vụ có thể làm đồng thời
- Tác vụ i cần thời gian d[i] để hoàn thành
- List điều kiện tiên quyết Q: Với [i, j] trong Q, tác vụ j chỉ được làm
sau khi tác vụ i hoàn thành xong

Objective: Sắp lịch để hoàn thành project sớm nhất có thể
Output: Thời gian sớm nhất tìm được*/

int n, m;
vector<int> d;
// earliest[i] = thời gian sớm nhất để bắt đầu làm tác vụ i
vector<int> earliest;
// adj[i] bao gồm j tức là i phải được thực hiện trước j
vector<vector<int>> adj;
// prevDegree[i] = k tức là có k tác vụ phải được hoàn thành trước i
vector<int> prevDegree;
// Ta cần tìm max(earliest[i] + d[i])

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    d.resize(n + 1);
    earliest.assign(n + 1, 0);
    adj.resize(n + 1);
    prevDegree.assign(n + 1, 0);

    for(int i = 1; i <= n; ++i) cin >> d[i];
    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        ++prevDegree[y];
    }

    queue<int> q;
    for(int i = 1; i <= n; ++i) {
        if(!prevDegree[i]) {
            earliest[i] = 0;
            q.push(i);
        }
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        int finish_time = earliest[u] + d[u];
        for(int v : adj[u]) {
            earliest[v] = max(earliest[v], finish_time);
            --prevDegree[v];

            if(!prevDegree[v]) {
                q.push(v);
            }
        }
    }

    int res = 0;
    for(int i = 1; i <= n; ++i) res = max(res, earliest[i] + d[i]);
    cout << res << endl;
}