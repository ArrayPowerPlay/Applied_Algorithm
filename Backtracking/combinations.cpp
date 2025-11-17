/*Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> x;

void Try(int i, const int &k, const int &n, vector<vector<int>> &res) {
    for(int v = 1; v <= n; ++v) {
        if(i > 0 && v <= x[i - 1]) continue;

        x.push_back(v);

        if(i == k - 1) {
            res.push_back(x);
            return;
        } else {
            Try(i + 1, k, n, res);
        }

        // backtrack
        x.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    Try(0, k, n, res);

    return res;
}

int main() {

}