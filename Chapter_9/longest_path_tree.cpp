#include <bits/stdc++.h>
using namespace std;

// Cho cây T = (V, E), mỗi cạnh (u,v) có trọng số w(u,v). Hãy tìm đường đi có 
// tổng trọng số lớn nhất trên T

int n, m;
int farthestNode;
vector<vector<pair<int, int>>> adj;
// Đánh dấu các đỉnh trong đường đi dài nhất
vector<int> bestPath;
int largestWeight;
// p[u] = v tức là v dẫn đến u trong quá trình duyệt dfs
vector<int> p;
vector<int> visited;
// dist[u] là khoảng cách từ đỉnh đang xét tới đỉnh u
vector<int> dist;

void dfs(int u) {
    visited[u] = 1;
    if(dist[u] > largestWeight) {
        largestWeight = dist[u];
        farthestNode = u;
    }
    for(auto &[v, w] : adj[u]) {
        if(visited[v]) continue;
        dist[v] = dist[u] + w;
        p[v] = u;
        dfs(v); 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    largestWeight = 0;
    adj.resize(n + 1);
    p.assign(n + 1, -1);
    visited.assign(n + 1, 0);
    dist.assign(n + 1, 0);

    for(int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    dfs(1);

    largestWeight = 0;
    p.assign(n + 1, -1);
    visited.assign(n + 1, 0);
    dist.assign(n + 1, 0);

    int x = farthestNode;
    dfs(x);
    int y = farthestNode;

    for(int u = y; u != -1; u = p[u]) {
        bestPath.push_back(u);
    }

    reverse(bestPath.begin(), bestPath.end());
    cout << largestWeight << endl;
    for(auto &u : bestPath) {
        cout << u << " ";
    }
}