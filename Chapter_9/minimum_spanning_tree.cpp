#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int n, m;
const int INF = 1e9;

void prim(vector<vector<pii>> &adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> inMST(n + 1, false);
    // min_edge[i] = khoảng cách ngắn nhất từ MST đến đỉnh i
    vector<bool> min_edge(n + 1, INF);
    // parent[i] là đỉnh nằm trước i trong thứ tự duyệt prim
    vector<int> parent(n + 1, -1);
    
    int start = 1;
    int num_edge = 0, total_weight = 0;
    min_edge[start] = 0;
    pq.push({0, 1});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(inMST[u]) continue;

        if(parent[u] != -1) {
            cout << parent[u] << " -> " << u << endl; 
            ++num_edge;
        }

        inMST[u] = 1;
        total_weight += d;
        
        for(auto &[v, w] : adj[u]) {
            if(!inMST[v] && min_edge[v] > w) {
                min_edge[v] = w;
                parent[v] = u;
                pq.push({min_edge[v], v});
            }
        }
    }

    if(num_edge != n - 1) cout << "Đồ thị không liên thông" << endl;
    else cout << "Total weight of MST: " << total_weight << endl;
}

int main() {
    cin >> n >> m;
    vector<vector<pii>> adj(n + 1);

    for(int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    prim(adj);
}