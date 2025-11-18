/*Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, 
and the combinations may be returned in any order.*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int k, int n, int start, int currSum, vector<int> &subset, vector<vector<int>> &res) {
    if(subset.size() == k && currSum == n) {
        res.push_back(subset);
        return;
    }

    if(subset.size() > k || currSum > n) {
        return;
    }

    for(int i = start; i <= 9; ++i) {
        subset.push_back(i);
        dfs(k, n, i + 1, currSum + i, subset, res);
        subset.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> subset;
    dfs(k, n, 1, 0, subset, res);
    return res;
}

int main() {

}