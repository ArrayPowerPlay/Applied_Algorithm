#include <bits/stdc++.h>
using namespace std;

/* Có n thành phố 1, 2,.., n
Giữa 2 thành phố, có đường đi 2 chiều kết nối chúng
Thành phố i có các tuyến xe bus để đi đến các thành phố lân cận
C[i]: Chi phí phải trả để lên xe buýt từ thành phố i
D[i]: Số lượng thành phố tối đa có thể đi trên tuyến xe này*/

/*Tìm đường đi từ thành phố 1 đến thành phố n với giá tiền ít nhất
Output: Giá tiền ít nhất tìm được*/

/*Cách làm: Áp dụng Dijkstra tìm đường đi có chi phí ngắn nhất từ 
thành phố 1 đến các thành phố còn lại. Tại mỗi thành phố, xét BFS
để xét các thành phố mà thành phố đó có thể đi tới*/

// n: số thành phố, m: số đường đi
int n, m;
const int INF = 1e9;
vector<int> C;
vector<int> D;
vector<vector<int>> adj;

// Chi phí nhỏ nhất từ đỉnh 'start' đến đỉnh n
int minCost(int start) {
    vector<int> dist(n + 1, INF);
    dist[start] = 0;
    // {Chi phí, Đỉnh}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if(cost > dist[u]) continue;
        // {Đỉnh, Số bước tới đỉnh đó thông qua đỉnh u}
        queue<pair<int, int>> q;
        q.push({u, 0});
        vector<int> visited(n + 1, 0);
        visited[u] = 1;

        while(!q.empty()) {
            auto [v, steps] = q.front();
            q.pop();

            if(steps > 0) {
                int newCost = cost + C[u];
                if(newCost < dist[v]) {
                    dist[v] = newCost;
                    pq.push({newCost, v});
                }
            }

            if(steps < D[u]) {
                for(int next : adj[v]) {
                    if(!visited[next]) {
                        visited[next] = 1;
                        q.push({next, steps + 1});
                    }
                }
            }
        }
    }
    // Trả về -1 nếu không tìm được đường đi
    return (dist[n] != INF) ? dist[n] : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    C.resize(n + 1);
    D.resize(n + 1);
    adj.resize(n + 1);

    for(int i = 1; i <= n; ++i) {
        cin >> C[i] >> D[i];
    }

    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << minCost(1) << endl;
}