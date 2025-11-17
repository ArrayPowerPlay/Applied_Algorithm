/*Given an array of distinct positive integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> x;

void backTrack(int k, int currSum, const vector<int> &candidates, const int &target, vector<vector<int>> &res) {
    if(currSum == target) {
        res.push_back(x);
        return;
    }
    
    for(int i = k; i < candidates.size(); ++i) {
        int v = candidates[i];
        
        x.push_back(v);
        backTrack(i, currSum + v, candidates, target, res);
        // backtrack
        x.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    backTrack(0, 0, candidates, target, res);

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}