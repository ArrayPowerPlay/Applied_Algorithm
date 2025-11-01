// Bài toán người đi du lịch nhưng số lượng thành phố phải đi qua
// rất lớn (có thể lên đến hàng trăm) nên ta không thể áp dụng được
// thuật toán nhánh cận. Lời giải ở đây sử dụng thuật toán tham lam
// Output: in ra n và thứ tự đường đi tới đích

#include <bits/stdc++.h>
using namespace std;

// Số lượng thành phố
const int INF = 1e8;
int n;
vector<vector<int>> dist;
vector<int> x;

// min path using greedy starting from city 'start'
pair<int, vector<int>> greedy(int start) {
    int f = 0;
    vector<int> visited(n + 1, 0);
    vector<int> x(n + 1);
    x[1] = start;
    visited[start] = 1;

    int cnt = 1;
    // khởi tạo bừa 1 giá trị cho k
    int k = 1;
    int curr = start;
    while(cnt < n) {
        int min_dist = INF;
        for(int i = 1; i <= n; ++i) {
            if(!visited[i]) {
                if(min_dist > dist[curr][i]) {
                    min_dist = dist[curr][i];
                    k = i;
                }
            }
        }
        visited[k] = 1;
        x[++cnt] = k;
        f += dist[curr][k];
        curr = k;
    }

    f += dist[k][start];
    return {f, x};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    dist.assign(n + 1, vector<int>(n + 1, 0));

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> dist[i][j];
        }
    }

    int res = INF;
    vector<int> best_path(n + 1);
    for(int i = 1; i <= n; ++i) {
        auto num = greedy(i);
        if(res > num.first) {
            res = num.first;
            best_path = num.second;
        }
    }
    
    cout << n << endl;
    for(int i = 1; i <= n; ++i) cout << best_path[i] << " ";
}