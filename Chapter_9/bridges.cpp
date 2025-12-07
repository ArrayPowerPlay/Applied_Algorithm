#include <bits/stdc++.h>
using namespace std;

/* Cho 1 đồ thị vô hướng, tính số đỉnh khớp, số cầu của dồ thị
Cầu, đỉnh khớp là cạnh/đỉnh mà bỏ cạnh/đỉnh đó đi thì số thành phần
liên thông của đồ thị tăng lên */

/*Ta định nghĩa cấu trúc Num[u] và Low[u] trong đó Num[u] là thứ tự
duyệt đỉnh u trong dfs và Low[u] là tổ tiên cao nhất trong cây dfs
mà đỉnh u có thể chạm tới thông qua đường đi được tạo bởi thuật toán
dfs*/

int n, m;
int T = 0;
// Số cầu
int numBrigdes = 0;
// Số đỉnh khớp
int numJoints = 0;
// Ma trận kề
vector<vector<int>> adj;
vector<int> num;
vector<int> low;
// Đỉnh liền kề trước đỉnh p trong thuật toán dfs
vector<int> p;
// joints[u] = true nếu u là một đinh khớp
vector<bool> joints;

void dfs(int u) {
    ++T;
    num[u] = T;
    low[u] = T;
    // Số con trực tiếp của đỉnh u
    int childs = 0;
    
    for(int v : adj[u]) {
        
        if(v == p[u]) continue;
        // Đỉnh v đã được thăm và [u, v] là 1 cạnh ngược
        if(num[v] > 0) {
            low[u] = min(low[u], num[v]);
        } else {
            p[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            // Với [u, v] là 1 cạnh xuôi, nếu low[v] > num[u] thì [u, v]
            // là 1 cầu
            if(low[v] > num[u]) ++numBrigdes;
            ++childs;
            // Nếu u là đỉnh gốc của đồ thị
            if(u == p[u]) {
                if(childs > 1) joints[u] = true;
            } else {
                if(low[v] >= num[u]) joints[u] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    adj.resize(n + 1);
    num.assign(n + 1, 0);
    low.resize(n + 1);
    joints.resize(n + 1);
    p.resize(n + 1);

    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; ++i) {
        if(!num[i]) {
            p[i] = i;
            dfs(i);
        }
    }

    for(int i = 1; i <= n; ++i) {
        if(joints[i]) ++numJoints;
    }

    cout << numJoints << " " << numBrigdes << endl;
    
}