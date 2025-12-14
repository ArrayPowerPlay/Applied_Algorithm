#include <bits/stdc++.h>
using namespace std;

/*Given an integer array nums, return all the different possible non-decreasing subsequences
of the given array with at least two elements. You may return the answer in any order.
*/

vector<int> num;

void dfs(int start, const int &n, vector<int> &a, vector<vector<int>> &res) {
    if(start == n) return;

    set<int> used;  // Track elements already used at this level
    for(int i = start; i < n; ++i) {
        // Skip if this element was already used at this level
        if(used.count(a[i])) continue;
        used.insert(a[i]);
        
        // Check if element is valid (non-decreasing)
        if(!num.empty() && a[i] < num[num.size() - 1]) continue;

        num.push_back(a[i]);
        if(num.size() >= 2) {
            res.push_back(num);
        }
        dfs(i + 1, n, a, res);
        num.pop_back();
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> res;
    int n = nums.size();
    dfs(0, n, nums, res);
    return res;
}