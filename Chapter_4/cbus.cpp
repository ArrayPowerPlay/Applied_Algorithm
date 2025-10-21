// There are n passengers 1, 2, …, n. The passenger i want to travel from point i to point i + n (i = 1,2,…,n) 
// There is a bus located at point 0 and has k places for transporting the passengers 
// (it means at any time, there are at most k passengers on the bus)
// You are given the distance matrix c in which c(i,j) is the traveling distance from point i to point j (i, j = 0,1,…, 2n)
// Compute the shortest route for the bus, serving n passengers and coming back to point 0. 

#include <bits/stdc++.h>
using namespace std;

// local minima
int f = 0; 
// global minima
int f_min = INT_MAX;
// minimum distance between two points
int c_min = INT_MAX;
unordered_map<string, int> memo;

bool check(int &, int, const int &, const int &, vector<int> &);
void try_min_path(int, int, const int &, const int &, vector<vector<int>> &, vector<int> &, vector<int> &);

void try_min_path(int t, int load, const int &k, const int &n, vector<vector<int>> &dist, vector<int> &visited, vector<int> &x) {
    string key;
    key.resize(2*n + 10);

    for(int i = 1; i <= 2*n; ++i) {
        key += (visited[i] ? '1' : '0');
    }
    key += '-' + to_string(load) + '-' + to_string(x[t - 1]);

    if(memo.count(key) && memo[key] <= f) {
        return;
    }
    memo[key] = f;

    for(int v = 1; v <= 2*n; ++v) {
        if(check(v, load, k, n, visited)) {
            x[t] = v;
            visited[v] = 1;
            f += dist[x[t - 1]][x[t]];

            // pick up passengers
            if(v <= n) ++load;
            // drop off passengers
            else --load;

            if(t == 2*n) {
                if(f + dist[x[2*n]][0] < f_min) {
                    f_min = f + dist[x[2*n]][0];
                }
            } else {
                if(f + (2*n + 1 - t) * c_min < f_min) {
                    try_min_path(t + 1, load, k, n, dist, visited, x);
                }
            }

            // backtrack
            if(v <= n) --load;
            else ++load;
            f -= dist[x[t - 1]][x[t]];
            visited[v] = 0;
        }   
    }
}

bool check(int &v, int load, const int &k, const int &n, vector<int> &visited) {
    if(visited[v]) return false;
    if(v > n) {
        // cannot drop off passengers without picking up passengers
        if(!visited[v - n]) return false;
    } else {
        // full of passengers
        if(load +  1 > k) return false;
    }
    return true;
}

int main() {
    // speed up input and output thread
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    // note if a point is being visited or note
    vector<int> visited(2*n + 1, 0);
    // store the order of points being visited
    vector<int> x(2*n + 1);
    x[0] = 0;
    // store the distance between two points
    vector<vector<int>> dist(2*n + 1, vector<int>(2*n + 1));
    
    for(int i = 0; i <= 2*n; ++i) {
        for(int j = 0; j <= 2*n; ++j) {
            cin >> dist[i][j];

            if(i != 0 && j != 0) {
                c_min = min(c_min, dist[i][j]);
            }
        }
    }

    try_min_path(1, 0, k, n, dist, visited, x);
    cout << f_min << endl;
}