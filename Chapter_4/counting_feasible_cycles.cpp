// Given n points on a plane, each point i has coordinates x[i] and y[i] 
// Count the number of cycles that start from a point, visit all the (n-1) other points exactly once, 
// and return to the starting point, such that the total distance of the cycle is less than or equal to a given number L
// Note that, the distance from point i to point j is the Manhattan distance |x[i] - x[j]| + |y[i] - y[j]|

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y): x(_x), y(_y) {};
    Point(): x(0), y(0) {};
};

int manhattan_dist(Point a, Point b) {
    int xa = a.x;
    int ya = a.y;
    int xb = b.x;
    int yb = b.y;
    return abs(xa - xb) + abs(ya - yb);
}   

int n, L, res = 0;
vector<Point> points;
vector<int> visited;
vector<int> x;
int dist = 0;

bool check(int v, int k) {
    if(visited[v]) return false;
    if(dist + manhattan_dist(points[x[k - 1]], points[v]) > L) return false;
    return true;
}

void Try(int k) {
    for(int v = 1; v <= n; ++v) {
        if(check(v, k)) {
            x[k] = v;
            visited[v] = 1;
            dist += manhattan_dist(points[x[k - 1]], points[x[k]]);

            if(k == n) {
                if(dist + manhattan_dist(points[x[k]], points[1]) <= L) res++;
            } else {
                Try(k + 1);
            }
            // backtrack
            visited[v] = 0;
            dist -= manhattan_dist(points[x[k - 1]], points[x[k]]);
        }
    }
}

int main() {
    cin >> n;
    points.resize(n + 1);
    visited.assign(n + 1, 0);
    x.resize(n + 1);

    for(int i = 1; i <= n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    cin >> L;

    visited[1] = 1;
    x[1] = 1;
    Try(2);
    cout << res << endl;
}