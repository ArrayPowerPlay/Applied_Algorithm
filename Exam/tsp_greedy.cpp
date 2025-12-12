#include <bits/stdc++.h>
using namespace std;

int n;
const int INF = 1e9;
vector<vector<int>> dist;
vector<int> visited;
vector<int> path;
int res = INF;
int cmin = INF;

void Try(int k, int curr) {
    if(k == n + 1) {
        int minCost = curr + dist[path[n]][1];
        if(minCost < res) res = minCost;
        return;
    }

    // Branch and bound
    if(curr + (n - k + 1) * cmin >= res) return;

    for(int v = 1; v <= n; ++v) {
        if(visited[v]) continue;
        visited[v] = 1;
        path[k] = v;

        Try(k + 1, curr + dist[path[k - 1]][path[k]]);

        // Backtrack
        visited[v] = 0;
    }
}

int tspBackTrack() {
    Try(2, 0);
    return res;
}

int tspGreedy() {
    int ans = 0;

    for(int k = 2; k <= n; ++k) {
        int bestV = -1;
        int minCost = INF;

        for(int v = 1; v <= n; ++v) {
            if(visited[v]) continue;

            int cost =  dist[path[k - 1]][v];
            if(cost < minCost) {
                minCost = cost;
                bestV = v;
            }
        }
        if(bestV == -1) return -1;
        path[k] = bestV;
        visited[bestV] = 1;
        ans += minCost;
    }
    ans += dist[path[n]][1];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    dist.assign(n + 1, vector<int>(n + 1, 0));
    visited.assign(n + 1, 0);
    path.resize(n + 1);
    path[1] = 1;
    visited[1] = 1;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> dist[i][j];
            if(i != j) {
                if(dist[i][j] < cmin) cmin = dist[i][j];
            }
        }
    }

    if(n <= 15) {
        cout << tspBackTrack() << endl;
    } else {
        cout << tspGreedy() << endl;
    }
}