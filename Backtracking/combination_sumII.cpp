/*Given a collection of positive candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> x;

void Try(int k, int currSum, const vector<int> &candidates, const int &target, vector<vector<int>> &res) {
    if(currSum == target) {
        res.push_back(x);
        return;
    }

    if(currSum > target) return;
    
    for(int i = k; i < candidates.size(); ++i) {
        // skip duplicates vectors
        if(i > k && candidates[i] == candidates[i - 1]) continue;

        int v = candidates[i];
        x.push_back(v);
        
        Try(i + 1, currSum + v, candidates, target, res);
        // backtrack
        
        x.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    Try(0, 0, candidates, target, res);
    return res;
}

int main() {

}