/*Trong giao dịch cổ phiếu, người giao dịch có thể mua cổ phiếu vào một ngày bất kỳ 
và bán vào một ngày trong tương lai. Cho trước danh sách giá cổ phiếu trong n ngày,
người giao dịch được phép thực hiện tối đa k giao dịch. Một giao dịch bao gồm việc 
mua và bán một cổ phiếu, và giao dịch mới chỉ có thể bắt đầu sau khi giao dịch trước
đó đã hoàn tất (không thể mua khi chưa bán). Nhiệm vụ của bạn là tìm lợi nhuận tối 
đa mà người giao dịch có thể đạt được từ tối đa k giao dịch*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    const int INF = 1e9;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    // dp[i][j][t] là xét tổng lợi nhuận lớn nhất tính tới ngày thứ i, qua tổng cộng j
    // giao dịch và trạng thái hiện tại là t (t = 0: không giữ cổ phiếu, t = 1: giữ cổ phiếu)
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, -INF)));

    dp[0][0][0] = 0;
    dp[0][0][1] = -a[0];
    int res = 0;

    for(int i = 1; i < n; ++i) {
        for(int j = 0; j <= k; ++j) {
            // State 0: không có cổ phiếu (vừa bán hoặc chưa mua)
            dp[i][j][0] = dp[i - 1][j][0]; // không làm gì
            if(j > 0) dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][1] + a[i]); // bán
            res = max(res, dp[i][j][0]);

            // State 1: có cổ phiếu (đã mua)
            dp[i][j][1] = dp[i - 1][j][1]; // giữ cổ phiếu
            dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][0] - a[i]); // mua
        }
    }

    cout << res << endl;
}
