#include <bits/stdc++.h>
using namespace std;

/*Given an array of distinct integers nums and a target integer target, 
return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, tgt;
    cin >> n >> tgt;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    // dp[i] = số cách để tổng bằng i
    vector<long long> dp(tgt + 1, 0);
    dp[0] = 1;  // một cách để tổng bằng 0: không chọn gì

    // có xét tới tính hoán vị của kết quả (ví dụ: (2, 0, 1) khác (1, 2, 0))
    for(int i = 1; i <= tgt; ++i) {
        for(int num : a) {
            if(i >= num) {
                dp[i] += dp[i - num];
            }
        }
    }

    cout << dp[tgt] << endl;
    return 0;
}
