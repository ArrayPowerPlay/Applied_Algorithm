#include <bits/stdc++.h>
using namespace std;

/* You are given a 0-indexed integer array nums, where nums[i] is a digit between 0 and 9 (inclusive).
The triangular sum of nums is the value of the only element present in nums after the following process terminates:

Let nums comprise of n elements. If n == 1, end the process. Otherwise, create a new 0-indexed integer 
array newNums of length n - 1.
For each index i, where 0 <= i < n - 1, assign the value of newNums[i] as (nums[i] + nums[i+1]) % 10, 
where % denotes modulo operator.
Replace the array nums with newNums.
Repeat the entire process starting from step 1.
Return the triangular sum of nums. */

int triagularSum(vector<int> &nums) {
    int len = nums.size();
    if(len == 1) return nums[0];
    if(len == 2) return (nums[0] + nums[1]) % 10;

    int res = 0;
    vector<int> row = getRow(len - 1);

    for(int i = 0; i < len; ++i) {
        res += (nums[i] * row[i]) % 10;
    }

    return res % 10;
}

// Get a vector row from a rowIndex in a pascal triangle of modulo 10
vector<int> getRow(int rowIndex) {
    vector<int> first(1);
    first[0] = 1;

    if(rowIndex == 0) return first;
    
    vector<int> second(2);
    second[0] = 1;
    second[1] = 1;
    
    if(rowIndex == 1) return second;
    
    vector<int> res;

    for(int i = 2; i <= rowIndex; ++i) {
        res.assign(rowIndex + 1, 1);
        for(int k = 1; k <= i - 1; ++k) {
            res[k] = (second[k - 1] + second[k]) % 10;
        }
        second = res;
    }

    return second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
