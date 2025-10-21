// Given a rectangle matrix of 0s and 1s, find the largest rectangle containing only 1s and return its area.
#include <bits/stdc++.h>
using namespace std;

int max_area = 0;

// histogram problem
void max_area_histogram(vector<int>& heights) {
    heights.push_back(0);
    // stack of index
    stack<int> s;
    int n = heights.size();

    for(int i = 0; i < n; ++i) {
        while(!s.empty() && heights[s.top()] >= heights[i]) {
            int height = heights[s.top()];
            int width;

            s.pop();

            if(s.empty()) {
                // upper limit index r = i
                // lower limit index l = -1
                // width = r - l - 1
                width = i;
            } else {
                // lower limit index = s.top()
                width = i - s.top() - 1;
            }

            max_area = max(max_area, height * width);
        }

        s.push(i);
    }
}

int main() {
    // height and width of the rectangle
    int h, w;
    cin >> h >> w;
    vector<vector<int>> rec(h, vector<int>(w));
    // histogram matrix
    vector<vector<int>> his(h, vector<int>(w));

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            cin >> rec[i][j];

            if(rec[i][j] == 0) his[i][j] = 0;
            else if(i == 0) his[i][j] = 1;
            else his[i][j] = his[i - 1][j] + 1;
        }
    }

    // solving histogram problem with regard to each row of the histogram matrix
    for(int i = 0; i < h; ++i) {
        max_area_histogram(his[i]);
    }

    cout << max_area << endl;
    
}