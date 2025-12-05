#include <bits/stdc++.h>
using namespace std;

/*Xuất phát từ đỉnh 0, người ta cần giao hàng tới n đỉnh (1,2,...,n). Chi phí giao hàng từ đỉnh tới
đỉnh j là c[i][j] (i,j = 0,...,n). Người giao hàng bắt đầu giao vào thời điểm 0. Đỉnh i chỉ được thăm
vào khoảng thời gian [e[i], l[i]]. Thời gian giao hàng tại đỉnh i là d[i]. Nếu đến đỉnh i trước thời 
điểm e[i] thì phải đợi tới thời điểm e[i] mới được giao hàng. Tìm lộ trình cho ra tổng chi phí giao hàng
nhỏ nhất*/

int n;
const int INF = 1e8;
int res = INF;
int curr = 0;
vector<int> e;
vector<int> l;
vector<int> d;
vector<vector<int>> c;
vector<int> sol;
vector<int> bestSol;
vector<int> visited;

bool check(int v, int k) {
    if(visited[v]) return false;
    
    int arrive_time = curr + c[sol[k - 1]][v];
    int start_time = max(arrive_time, e[v]);
    if(start_time + d[v] > l[v]) return false;
    return true;
}

void Try(int k) {
    if(k == n + 1) {
        if(res > curr) {
            res = curr;
            bestSol = sol;
        }
        return;
    }

    if(curr >= res) return;

    for(int v = 1; v <= n; ++v) {
        if(!check(v, k)) continue;

        visited[v] = 1;
        sol[k] = v;
        // Chi phí di chuyển đến điểm v
        curr += c[sol[k - 1]][sol[k]];
        int add;
        // Chi phí chờ đợi để lấy hàng tại điểm v
        if(curr < e[v]) add = e[v] - curr + d[v];
        else add = d[v];
        curr += add;

        Try(k + 1);

        // Backtrack
        visited[v] = 0;
        curr -= c[sol[k - 1]][sol[k]];
        curr -= add;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    e.resize(n + 1);
    l.resize(n + 1);
    d.resize(n + 1);
    sol.resize(n + 1);
    bestSol.resize(n + 1);
    visited.assign(n + 1, 0);
    c.assign(n + 1, vector<int>(n + 1, 0));

    for(int i = 1; i <= n; ++i) {
        cin >> e[i] >> l[i] >> d[i];
    }

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            cin >> c[i][j];
        }
    }

    visited[0] = 1;
    sol[0] = 0;
    Try(1);

    cout << res << endl;
    for(int i = 1; i <= n; ++i) cout << bestSol[i] << " "; 
}