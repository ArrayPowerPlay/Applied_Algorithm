#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    const int INF = 1e8;
    vector<int> e(n + 1);
    vector<int> l(n + 1);
    vector<int> d(n + 1);
    vector<vector<int>> c(n + 1, vector<int>(n + 1));
    vector<int> sol(n + 1);
    vector<int> visited(n + 1, 0);

    for(int i = 1; i <= n; ++i) {
        cin >> e[i] >> l[i] >> d[i];
    }

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            cin >> c[i][j];
        }
    }

    // Thời điểm bắt đầu lộ trình
    int curr = 0;
    // Tại mỗi thời điểm, chọn đỉnh có chi phí giao hàng nhỏ nhất
    // Chi phí giao hàng ở đây bao gồm chi phí di chuyển tới điểm đó và chi phí vận chuyển
    // tại điểm đó
    for(int k = 1; k <= n; ++k) {
        int bestV = -1;
        int bestCost = INF;
        bool found = false;

        for(int v = 1; v <= n; ++v) {
            if(visited[v]) continue;

            int start_time = curr + c[sol[k - 1]][v];
            int start = max(start_time, e[v]);
            if(start + d[v] > l[v]) continue;

            // Tính chi phí
            int cost = c[sol[k - 1]][v];
            if(start_time < e[v]) {
                cost += e[v] - start_time + d[v];
            } else {
                cost += d[v];
            }

            // Đánh dấu chi phí tốt nhất và đỉnh tốt nhất
            if(cost < bestCost) {
                bestCost = cost;
                bestV = v;
                found = true;
            }
        }
        if(!found) {
            // Không tìm được lời giải
            cout << -1 << endl;
            return 0;
        }
        sol[k] = bestV;
        curr += bestCost;
        visited[bestV] = 1;
    }

    cout << curr << endl;
    for(int i = 1; i <= n; ++i) cout << sol[i] << " "; 
}