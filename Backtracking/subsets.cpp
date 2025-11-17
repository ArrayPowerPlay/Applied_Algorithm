/*Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int start, vector<int> &subset, const vector<int> &nums, vector<vector<int>> &res) {
    
    res.push_back(subset);

    for(int i = start; i < nums.size(); ++i) {
        subset.push_back(nums[i]);
        dfs(i + 1, subset, nums, res);
        subset.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> subset;

    dfs(0, subset, nums, res);
    return res;
}

int main() {

}