#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9;
int n, m;

void dijkstra(int start, vector<vector<pii>> &adj) {
    // pq chứa các pair dạng {w, d} với w là khoảng cách từ tập đã xét tới đỉnh d
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(n + 1, INF);
    vector<int> p(n + 1, -1);
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) continue;
        for(auto &[v, w] : adj[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                p[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        if(dist[i] == INF) {
            cout << "There's no path from " << start << " to " << i << endl;
            continue;
        }

        cout << "Distance from " << start << "to " << i << " " << dist[i] << endl;
        cout << "Path: ";

        stack<int> path;
        for(int v = i; v != -1; v = p[v]) path.push(v);
        while(!path.empty()) {
            int node = path.top();
            path.pop();
            cout << node << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> m;
    vector<vector<pii>> adj(n + 1);

    for(int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    int start;
    cin >> start;
    dijkstra(start, adj);
}