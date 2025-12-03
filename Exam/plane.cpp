#include <bits/stdc++.h>
using namespace std;

/*Cho n điểm (1 -> n) trên 1 mặt phẳng 2D. Mỗi điểm có tọa độ x[i], y[i]. Tìm số chu trình
(bắt đầu từ 1 điểm bất kỳ, đi qua tất cả n - 1 điểm khác đúng 1 lần và quay về điểm xuất phát)
sao cho tổng độ dài chu trình không vượt quá L (khoảng cách giữa 2 điểm được tính bằng khoảng
cách Mahattan)*/

struct Point {
    int x;
    int y;
};

int n;
int res = 0;
vector<int> visited;
vector<Point> points;
vector<int> path;

int dist(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void Try(int k, int currDist, const int &L) {
    if(k == n + 1) {
        int totalDist = currDist + dist(points[path[n]], points[1]);
        if(totalDist <= L) ++res;
        return;
    }

    if(currDist > L) return;

    for(int v = 1; v <= n; ++v) {
        if(visited[v]) continue;

        visited[v] = 1;
        path[k] = v;
        currDist += dist(points[path[k - 1]], points[path[k]]);

        Try(k + 1, currDist, L);

        visited[v] = 0;
        currDist -= dist(points[path[k - 1]], points[path[k]]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    points.resize(n + 1);
    visited.assign(n + 1, 0);
    path.resize(n + 1);

    for(int i = 1; i <= n; ++i) {
        int xx, yy;
        cin >> xx >> yy;
        points[i].x = xx;
        points[i].y = yy;
    }

    int L;
    cin >> L;
    
    path[1] = 1;
    visited[1] = 1;
    Try(2, 0, L);

    cout << res << endl;

}