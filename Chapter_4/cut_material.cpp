// Given a material having the shape rectangle with height H and width W
// We need to cut this material into n smaller rectangle submaterials of 
// size (h1,w1), (h2, w2), ..., (hn, wn)
// Write a program to check if we can perform this cut

#include <bits/stdc++.h>
using namespace std;

// height, width of the large rectangle and number of sub-rectangles
int height, width, n;
// check if a cell in the rectangle has been filled by a sub-rectangle or not
vector<vector<int>> visited;
// height, width of sub-rectangles
vector<int> h, w;
// final result
bool cutable = false;

void place(int, int, int, int, int);
bool check(int, int, int, int);
void cut_material(int);

void cut_material(int k) {
    if(k == n + 1) {
        cutable = true;
        return;
    }

    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            // rotate the sub-rectangle or not
            // 1: yes, 0: no
            for(int v = 1; v >= 0; --v) {
                int hh = v ? w[k] : h[k];
                int ww = v ? h[k] : w[k];

                if(check(i, j, hh, ww)) {
                    place(i, j, hh, ww, 1);
                    cut_material(k + 1);
                    // backtrack
                    if(cutable) return;
                    place(i, j, hh, ww, 0);
                }
            }
        }
    }
}

// mark all cells of a sub-rectangle to being visited or not
void place(int r, int c, int h, int w, int val) {
    for(int i = r; i < r + h; ++i) {
        for(int j = c; j < c + w; ++j) {
            visited[i][j] = val;
        }
    }
}

// check if we can place a sub-rectangle at position (r, c) into current rectangle
// without overlapping with other sub-rectangles
bool check(int r, int c, int h, int w) {
    if(r + h > height || c + w > width) return false;
    
    for(int i = r; i < r + h; ++i) {
        for(int j = c; j < c + w; ++j) {
            if(visited[i][j]) return false;
        }
    }
    
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int total_sum = 0;
    cin >> height >> width >> n;
    visited.assign(height, vector<int>(width, 0));
    h.resize(n + 1);
    w.resize(n + 1);
    
    for(int i = 1; i <= n; ++i) {
        cin >> h[i] >> w[i];
        total_sum += h[i] * w[i];
    }

    if(total_sum > height * width) {
        cout << 0 << endl;
        return 0;
    }

    cut_material(1);
    cout << cutable << endl;
}
