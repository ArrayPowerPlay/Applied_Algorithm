/*Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. 
More formally, if you are on index i on the current row, you may move to either 
index i or index i + 1 on the next row.*/

#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle) {
    int height = triangle.size();
    if(height == 1) return triangle[0][0];

    vector<vector<int>> dp = triangle;
    for(int i = height - 2; i >= 0; --i) {
        for(int j = 0; j < i + 1; ++j) {
            dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]); 
        }
    }

    return dp[0][0];
}

int main() {

}