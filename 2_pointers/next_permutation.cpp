#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    if(n <= 1) return;

    // Step 1: Find the largest index i such that nums[i] < nums[i+1]
    int i = n - 2;
    while(i >= 0 && nums[i] >= nums[i + 1]) {
        --i;
    }
    
    // Step 2: If no such index exists, reverse entire array (it's the last permutation)
    if(i < 0) {
        reverse(nums.begin(), nums.end());
        return;
    }
    
    // Step 3: Find the largest index j > i such that nums[i] < nums[j]
    int j = n - 1;
    while(j > i && nums[j] <= nums[i]) {
        --j;
    }
    
    // Step 4: Swap nums[i] and nums[j]
    swap(nums[i], nums[j]);
    
    // Step 5: Reverse the suffix starting at nums[i+1]
    reverse(nums.begin() + i + 1, nums.end());
} 

int main() {

}