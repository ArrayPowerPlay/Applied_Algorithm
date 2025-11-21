#include <bits/stdc++.h>
using namespace std;

/*Cho dãy A gồm n số nguyên dương khác nhau. Đếm số tập con khác nhau của A sao cho
tổng các phần tử trong tập con lớn hơn hoặc bằng LB và nhỏ hơn hoặc bằng UB*/

int res = 0;

void dfs(int start, int currSum, const int &n, vector<int> &nums, const int &LB, const int &UB) {
    
    for(int i = start; i < n; ++i) {
        currSum += nums[i];
        if(currSum >= LB && currSum <= UB) ++res;
        dfs(i + 1, currSum, n, nums, LB, UB);
        // Backtrack
        currSum -= nums[i];
    }
}

int numSubsets(vector<int> &nums, const int &LB, const int &UB) {
    int n = nums.size();
    dfs(0, 0, n, nums, LB, UB);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];

    int LB, UB;
    cin >> LB >> UB;
    cout << numSubsets(nums, LB, UB) << endl;
}