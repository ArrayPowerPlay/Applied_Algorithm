/*Given a collection of numbers, nums, that might contain duplicates, 
return all possible unique permutations in any order.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> x;
vector<int> visited;

bool check(int i, vector<int> nums) {
    if(visited[i]) return false;
    else {
        if(i == 0) return true;
        // Nếu phần tử trước chưa được chọn và bằng phần tử hiện tại thì bỏ qua
        if(visited[i - 1] == 0 && nums[i - 1] == nums[i]) return false;
        return true;
    }
}

void Try(int k, const vector<int> &nums, vector<vector<int>> &res) {
    for(int i = 0; i < nums.size(); ++i) {
        if(!check(i, nums)) continue;

        int v = nums[i];
        visited[i] = 1;
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

vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    visited.assign(nums.size(), 0);
    vector<vector<int>> res;
    Try(0, nums, res);
    return res;
}

int main() {

}