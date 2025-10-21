// A team of K identical trucks needs to be assigned to transport goods from point 0 to points 1,2,...,N 
// and back to point 0. The distance traveled from point i to point j is c(i,j)
// Each truck has a payload of Q (each trip can only transport a maximum of Q boxes)
// Each delivery point i has a required quantity of goods of d[i] boxes, i = 1,..., N.
// A transportation plan needs to be developed so that
// Each delivery point is delivered by exactly 1 truck
// The total amount of goods on the truck does not exceed the payload of that truck
// The total length of the route of the trucks is the smallest

#include <bits/stdc++.h>
using namespace std;

int n, K, Q;
int f = 0;
int f_min = INT_MAX;
int c_min = INT_MAX;
// current load of each truck
vector<int> load;
// required goods of each point
vector<int> d;
// note visited points
vector<int> visited;
// distance between two points
vector<vector<int>> c;
// y[k] = first point to be delivered of truck k_th
vector<int> y;
// x[i] = next point to be delivered after point i
vector<int> x;
// number of trucks that truely scheduled for delivery
int nbR = 0;
// number of routes (which connects two consecutive points)
int segments = 0;

// check if x[s] (delivered by truck k_th) can get value v
bool checkX(int v, int k) {
    if(v > 0 && visited[v]) return false;
    if(load[k] + d[v] > Q) return false;
    return true;
}

// try some value for x[s]
void TRY_X(int s, int k) {
    if(s == 0) {
        if(k < K) {
            TRY_X(y[k + 1], k + 1);
        } else {
            if(segments == nbR + n) {
                f_min = min(f_min, f);
            }
        }
    } else {
        for(int v = 0; v <= n; ++v) {
            if(checkX(v, k)) {
                x[s] = v;
                visited[v] = true;
                load[k] += d[v];
                f += c[s][v];
                segments++;

                if(v > 0) {
                    if(f + (n + nbR - segments)*c_min < f_min) {
                        TRY_X(v, k);
                    }
                } else {
                    if(k == K) {
                        if(segments == n + nbR) f_min = min(f, f_min);
                    } else {
                        if(f + (n + nbR - segments)*c_min < f_min) {
                            TRY_X(y[k + 1], k + 1);
                        }
                    }
                }

                // backtrack
                visited[v] = false;
                load[k] -= d[v];
                f -= c[s][v];
                segments--;
            }
        }
    }
}

// check if truck k_th can get y[k] = v;
bool checkY(int v, int k) {
    if(v == 0) return true;
    if(load[k] + d[v] > Q) return false;
    if(visited[v]) return false;
    return true;
}

// try the first point to be delivered by truck k_th
void TRY_Y(int k) {
    int s = 0;
    if(y[k - 1] > 0) s = y[k - 1] + 1;
    for(int v = s; v <= n; ++v) {
        if(checkY(v, k)) {
            y[k] = v;
            if(v > 0) segments++;
            visited[v] = true;
            f += c[0][v];
            load[k] += d[v];

            if(k < K) {
                TRY_Y(k + 1);
            } else {
                nbR = segments;
                TRY_X(y[1], 1);
            }

            // backtrack
            if(v > 0) segments--;
            visited[v] = false;
            f -= c[0][v];
            load[k] -= d[v];
        }
    }
}

int main() {
    cin >> n >> K >> Q;
    d.resize(n + 1);
    visited.assign(n + 1, 0);
    load.resize(K + 1);
    c.resize(n + 1, vector<int>(n + 1));
    y.resize(K + 1);
    x.resize(n + 1);

    d[0] = 0;
    y[0] = 0;

    for(int i = 1; i <= n; ++i) cin >> d[i];
    
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            cin >> c[i][j];
            c_min = min(c_min, c[i][j]);
        }
    }

    TRY_Y(1);
    cout << f_min << endl;
}