#include <bits/stdc++.h>
using namespace std;

int n, m;
const int INF = 1e9;
// Lưu các đỉnh xuất phát
vector<int> src;
vector<vector<int>> adj;

void multi_source_BFS() {
    vector<int> dist(n + 1, INF);
    queue<int> q;
    for(auto &x : src) {
        q.push(x);
        dist[x] = 0;
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto &v : adj[u]) {
            if(dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        if(dist[i] == INF) cout << "Đỉnh " << i << " không thể được nối từ tập các đỉnh nguồn" << endl;
        else {
            cout << "Khoảng cách ngắn nhất từ tập các đỉnh nguồn tới đỉnh " << i << " là: " << dist[i] << endl;
        }
    }

}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);

    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    } 

    int t;
    cin >> t;
    src.resize(t);
    for(int i = 0; i < t; ++i) cin >> src[i];

    multi_source_BFS();
}