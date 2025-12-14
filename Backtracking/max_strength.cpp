#include <bits/stdc++.h>
using namespace std;

/*You are given a 0-indexed integer array nums representing the score of students in an exam. 
The teacher would like to form one non-empty group of students with maximal strength, where 
the strength of a group of students of indices i0, i1, i2, ... , ik is defined as:
nums[i0] * nums[i1] * nums[i2] * ... * nums[ik​].

Return the maximum strength of a group the teacher can create.*/

const int INF = 1e9;
long long maxStre = -INF;
long long curr = 1;

void dfs(int start, const int &n, vector<int> &nums) {
    if(start == n) return;
    
    for(int i = start; i < n; ++i) {
        int pre = curr;
        curr *= nums[i];
        maxStre = max(maxStre, curr);
        
        dfs(i + 1, n, nums);
        curr = pre;
    }
}

long long maxStrength(vector<int> &nums) {
    int n = nums.size();
    dfs(0, n, nums);
    return maxStre;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}