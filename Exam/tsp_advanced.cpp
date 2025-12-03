#include <bits/stdc++.h>
using namespace std;

// Bài toán TSP nhưng có thêm điều kiện đỉnh nào phải được thăm trước đỉnh nào
// trong chu trình

int n;
const int INF = 1e8;
// Chi phí tối ưu
int res = INF;
// Cạnh có độ dài nhỏ nhất
int cmin = INF;
// Chi phí hiện tại
int curr = 0;
// Đánh dấu các đỉnh đã thăm
vector<int> visited;
// Vector lưu lời giải theo từng bước 
vector<int> sol;
// Ma trận khoảng cách
vector<vector<int>> dist;
// prevRequire[y] = x tức là đỉnh x phải được thăm trước đỉnh y
vector<vector<int>> prevRequire;
// Vector lưu lời giải tốt nhất
vector<int> bestSol;

bool check(int k, int i) {
    if(visited[i]) return false;

    for(int point : prevRequire[i]) {
        if(!visited[point]) return false;
    }
    return true;
}

void Try(int k) {
    if(curr + (n - k + 1) * cmin >= res) return;

    if(k == n + 1) {
        int minDist = curr + dist[sol[n]][sol[1]];
        if(res > minDist) {
            res = minDist;
            bestSol = sol;
        }
        return;
    }

    for(int i = 1; i <= n; ++i) {
        if(!check(k, i)) continue; 


        visited[i] = 1;
        sol[k] = i;
        int add = 0;
        if(k > 1) add = dist[sol[k - 1]][sol[k]];
        curr += add;

        Try(k + 1);

        visited[i] = 0;
        curr -= add;     
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    visited.assign(n + 1, 0);
    sol.resize(n + 1);
    dist.assign(n + 1, vector<int>(n + 1, 0));
    prevRequire.resize(n + 1);
    bestSol.resize(n + 1);

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> dist[i][j];
            if(i != j) cmin = min(cmin, dist[i][j]);
        }
    }

    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        int x, y;
        cin >> x >> y;
        prevRequire[y].push_back(x);
    }

    Try(1);
    cout << res << endl;
    for(int i = 1; i <= n; ++i) cout << bestSol[i] << " ";
}