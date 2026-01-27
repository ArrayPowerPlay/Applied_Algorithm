#include <bits/stdc++.h>
using namespace std;

int n, m;

void bfs(int start, vector<vector<int>> &adj) {
    queue<int> q;
    vector<int> dist(n + 1, -1);
    vector<int> p(n + 1, -1);
    q.push(start);
    dist[start] = 0;

    while(!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();

        for(int &v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                p[v] = u;
                q.push(v);
            }
        }
    }

    cout << endl;
    for(int u = 1; u <= n; ++u) {
        if(dist[u] == -1) continue;

        cout << "Length path from " << start << " to " << u << ": " << dist[u] << endl;
        stack<int> st;
        for(int v = u; v != -1; v = p[v]) st.push(v);
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            cout << node << " ";
        }
        cout << endl;
    }
}

void findConnectComponent(vector<vector<int>> &adj) {
    // Đếm số thành phần liên thông
    int num = 0;
    for(int i = 1; i <= n; ++i) {
        if(!visited[i]) {
            ++num;
            dfs(i, adj);
            cout << "Connected component: " << num << endl;
        }
        cout << endl;
    }
}

vector<int> visited;

void dfs(int start, vector<vector<int>> &adj) {
    visited[start] = 1;
    cout << start << " ";

    for(auto &u : adj[start]) {
        if(!visited[u]) {
            dfs(u, adj);
        }
    }
}

int main() {
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    visited.assign(n + 1, 0);

    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int start;
    cin >> start;
    bfs(start, adj);
}