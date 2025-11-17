/*Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> x;
vector<int> visited;

void Try(int k, const vector<int> &nums, vector<vector<int>> &res) {
    for(int i = 0; i < nums.size(); ++i) {
        if(visited[i]) continue;

        visited[i] = 1;
        int v = nums[i];
        x.push_back(v);

        if(k == nums.size() - 1) {
            res.push_back(x);
        } else {
            Try(k + 1, nums, res);
        }
        
        // backtrack
        visited[i] = 0;
        x.pop_back();
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    visited.assign(nums.size(), 0);
    Try(0, nums, res);

    return res;
}

int main() {

}