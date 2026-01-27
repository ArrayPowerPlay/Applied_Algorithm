#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int n, m, t;
// Chứa tập các đỉnh nguồn
vector<int> src;
vector<vector<pii>> adj;
const int INF = 1e9;

void multi_source_dijkstra(vector<int> &src, vector<vector<pii>> &adj) {
    vector<int> dist(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for(auto &s : src) {
        dist[s] = 0;
        pq.push({0, s});
    }

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) continue;

        for(auto &[v, w] : adj[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        if(dist[i] == INF) cout << "No path from sources to " << i << endl;
        else {
            cout << "Distance from " << i << " to the nearest point in source is: " << dist[i] << endl;
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    adj.resize(n + 1);
    for(int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    cin >> t;
    src.resize(t + 1);
    for(int i = 1; i <= t; ++i) cin >> src[i];

    multi_source_dijkstra(src, adj);
}
