#include <bits/stdc++.h>
using namespace std;

/*Cho 1 dãy số nguyên. Dãy con của A là dãy thu được bằng cách loại bỏ đi 1 số phần tử của A, hoặc không
loại bỏ phần tử nào. Một dãy con được gọi là dãy con chẵn lẻ nếu tất cả các phần tử của dãy con đều chẵn
hoặc đều lẻ. Tìm độ dài dãy con chẵn lẻ tăng dài nhất của A*/

int maxOddIncreasingSubsequence(vector<int> &nums) {
    int n = nums.size() - 1;
    int res = 0;
    // Độ dài dãy con lẻ tăng dài nhất kết thúc tại index i = dp[i]
    vector<int> dp(n + 1, 0);
    
    for(int i = 1; i <= n; ++i) {
        int curr = nums[i];
        if(curr % 2 == 0) dp[i] = 0;
        else {
            dp[i] = 1;
            for(int k = 1; k < i; ++k) {
                if(nums[k] < curr && nums[k] % 2 == 1) {
                    dp[i] = max(dp[i], dp[k] + 1);
                } 
            }
        }

        res = max(res, dp[i]);
    }
    return res;
}

int maxEvenIncreasingSubsequence(vector<int> &nums) {
    int n = nums.size() - 1;
    int res = 0;
    // Độ dài dãy con chẵn tăng dài nhất kết thúc tại index i = dp[i]
    vector<int> dp(n + 1, 0);
    
    for(int i = 1; i <= n; ++i) {
        int curr = nums[i];
        if(curr % 2 == 1) dp[i] = 0;
        else {
            dp[i] = 1;
            for(int k = 1; k < i; ++k) {
                if(nums[k] < curr && nums[k] % 2 == 0) {
                    dp[i] = max(dp[i], dp[k] + 1);
                } 
            }
        }

        res = max(res, dp[i]);
    }
    return res;
}

int maxOddEvenIncreasingSubsequence(vector<int> &nums) {
    int maxEven = maxEvenIncreasingSubsequence(nums);
    int maxOdd = maxOddIncreasingSubsequence(nums);
    return max(maxEven, maxOdd);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];

    cout << maxOddEvenIncreasingSubsequence(a) << endl;
}