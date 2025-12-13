#include <bits/stdc++.h>
using namespace std;

// Return all the triplets [nums[i], nums[j], nums[k]] such that:
// i != j, j != k and nums[i] + nums[j] + nums[k] == 0

vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    
    for(int k = 0; k < n - 2; ++k) {
        // Skip duplicate k values
        if(k > 0 && nums[k] == nums[k - 1]) continue;
        
        // If nums[k] > 0, no solution possible (array is sorted)
        if(nums[k] > 0) break;
        
        int i = k + 1, j = n - 1;
        while(i < j) {
            int sum = nums[i] + nums[j];
            if(sum == -nums[k]) {
                res.push_back({nums[k], nums[i], nums[j]});
                
                // Skip duplicate i values
                while(i < j && nums[i] == nums[i + 1]) ++i;
                // Skip duplicate j values
                while(i < j && nums[j] == nums[j - 1]) --j;
                
                ++i;
                --j;
            } else if(sum < -nums[k]) {
                ++i;
            } else {
                --j;
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}