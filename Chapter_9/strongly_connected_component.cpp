#include <bits/stdc++.h>
using namespace std;

/*Đếm số thành phần liên thông mạnh trên đồ thị có hướng
- TPLTM: một tập con có nhiều đỉnh nhất có thể và liên thông mạnh
- Liên thông mạnh: giữa 2 đỉnh bất kỳ: có đường đi từ đỉnh này đến
đỉnh kia và ngược lại

Output: Số thành phần liên thông mạnh của đồ thị*/

int n, m;
// adj[i] gồm j tức là i nối j trong đồ thị ban đầu
vector<vector<int>> adj;
// rev_adj[i] gồm j tức là i nối j trong đồ thị đảo cạnh
vector<vector<int>> rev_adj;
// Thứ tự kết thúc các đỉnh (kết thúc cuối cùng thì nằm ở đỉnh stack)
stack<int> finish_order;
vector<int> visited;

// dfs trên đồ thị ban đầu
void dfs1(int u) {
    visited[u] = 1;
    for(int v : adj[u]) {
        if(!visited[v]) dfs1(v);
    }
    finish_order.push(u);
}

// dfs trên đồ thị đảo ngược cạnh
// vector component lưu các đỉnh trong 1 SCC
void dfs2(int u, vector<int> &component) {
    visited[u] = 1;
    component.push_back(u);
    for(int v : rev_adj[u]) {
        if(!visited[v]) dfs2(v, component);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    adj.resize(n + 1);
    rev_adj.resize(n + 1);

    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        rev_adj[y].push_back(x);
    }

    visited.assign(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        if(!visited[i]) dfs1(i);
    }

    int res = 0;
    visited.assign(n + 1, 0);
    
    // Lưu các đỉnh của tất cả các SCC
    vector<vector<int>> scc_list;
    
    while(!finish_order.empty()) {
        int u = finish_order.top();
        finish_order.pop();

        if(!visited[u]) {
            vector<int> component;
            dfs2(u, component);
            scc_list.push_back(component);

            ++res;
        }
    }

    cout << "Number of SCC: " << res << endl;
    cout << "Nodes of each SCC: " << endl;
    for(auto &d : scc_list) {
        for(int &u : d) cout << u << " ";
        cout << endl;
    }
}