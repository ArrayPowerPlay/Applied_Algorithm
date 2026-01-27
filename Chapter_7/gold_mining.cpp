#include <bits/stdc++.h>
using namespace std;

// Có n nhà kho chứa vàng cùng nằm trên một đường thẳng. Nhà kho i có lượng vàng
// là a_i và nằm ở vị trí i. Tìm một tập các nhà kho có tổng lượng vàng lớn nhất.

// Constraint: Khoảng cách giữa 2 nhà kho liền kề phải nằm trong [L1, L2]
// Output: Tổng lượng vàng tìm được 

// Solution using DP
// Complexity: O(n2)
int goldMining(const int &n, vector<int> &nums, const int &L1, const int &L2) {
    // Edge cases
    if(n == 0) return 0;
    if(n == 1) return nums[1]; 
    // dp[i] = tổng lượng vàng tìm được nếu nhà kho cuối cùng kết thúc tại vị trí i
    vector<int> dp(nums.begin(), nums.end());
    int best = dp[1];
    
    for(int i = 2; i <= n; ++i) {
        for(int c = L1; c <= L2; ++c) {
            if(i < c) break;
            dp[i] = max(dp[i], nums[i] + dp[i - c]);
        }
        best = max(best, dp[i]);
    }

    return best;
}

// Advanced solution using DP + deque 
// Complexity: O(n)
int goldMiningVer2(const int &n, vector<int> &nums, const int &L1, const int &L2) {
    // Lưu trữ chỉ số các ứng cử viên j tham gia vào việc xác định bài toán con dp[j]
    // theo thời gian
    // d được sắp xếp sao cho phần tử j có dp[j] lớn nhất được xếp ở đầu deque
    // Tức là lưu trữ các phần tử i < j mà dp[i] > dp[j]
    deque<int> d;
    vector<int> dp(n + 1); 
    int best = 0;

    for(int i = 1; i <= n; ++i) {
        while(!d.empty() && d.front() < i - L2) d.pop_front();

        int j = i - L1;
        if(j >= 1) {
            while(!d.empty() && dp[d.back()] < dp[j]) d.pop_back();
            d.push_back(j);
        }
        dp[i] = nums[i] + (d.empty() ? 0 : dp[d.front()]);
        best = max(best, dp[i]);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, L1, L2;
    cin >> n >> L1 >> L2;
    vector<int> a(n + 1);

    for(int i = 1; i <= n; ++i) cin >> a[i];

    cout << goldMining(n, a, L1, L2) << endl;
    cout << goldMiningVer2(n, a, L1, L2) << endl;
}