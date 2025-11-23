#include <bits/stdc++.h>
using namespace std;

// Cho dãy số có n số nguyên. Dãy con là dãy chứa các phần tử liên tiếp của dãy số ban đầu. 
// Ta cần tìm tổng lớn nhất của dãy con chẵn (các phần tử trong dãy đều chẵn)
// Trả về kết quả bằng -1 nếu không tìm được dãy con nào thỏa mãn yêu cầu

// Solution using DP
int maxSumEvenSub(const int &n, vector<int> &nums) {
    // dp[i] = tổng lớn nhất của dãy con chẵn kết thúc tại vị trí i
    vector<int> dp(n, -1);
    dp[0] = (nums[0] % 2 == 0) ? nums[0] : -1;
    int best = dp[0];

    for(int i = 1; i < n; ++i) {
        if(nums[i] % 2 == 0) {
            if(nums[i - 1] % 2 == 1) {
                dp[i] = nums[i];
            } else {
                dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            }
        }
        best = max(best, dp[i]);

    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; ++i) cin >> a[i];

    cout << maxSumEvenSub(n, a) << endl;
}