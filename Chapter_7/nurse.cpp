#include <bits/stdc++.h>
using namespace std;

// Lập lịch làm việc cho y tá trong n ngày liên tiếp
// Ràng buộc: chỉ có đúng 1 ngày nghỉ giữa 2 chu kỳ làm việc liên tiếp
// Một chuỗi ngày làm việc có độ dài trong đoạn [K1, K2]
// Output: số cách sắp lịch làm việc

// Solution 1: using backtracking
int res = 0;

void backTrack(int k, int currOnes, int currZeros, const int &n, const int &K1, const int &K2) {
    if(k == n) {
        if((currOnes >= K1 && currOnes <= K2) || currOnes == 0) {
            res++;
        }
        return;
    }

    if(currZeros == 1) {
        backTrack(k + 1, 1, 0, n, K1, K2);
    } else if(currOnes >= K1 && currOnes < K2) {
        backTrack(k + 1, 0, 1, n, K1, K2);
        backTrack(k + 1, currOnes + 1, 0, n, K1, K2);
    } else if(currOnes < K1) {
        // Luôn sắp lịch bắt đầu bằng 1 ngày làm việc
        backTrack(k + 1, currOnes + 1, 0, n, K1, K2);
    } else {
        backTrack(k + 1, 0, 1, n, K1, K2);
    }
}

int numArrangeWorkSchedule(const int &n, const int &K1, const int &K2) {
    res = 0;
    // Sắp lịch bắt đầu bằng 1 ngày làm việc
    backTrack(0, 0, 0, n, K1, K2);
    // Sắp lịch bắt đầu bằng 1 ngày nghỉ
    backTrack(1, 0, 1, n, K1, K2);
    return res;
}

// Solution 2: using DP
int numArrangeWorkSchedule2(const int &n, const int &K1, const int &K2) {
    // dp[i][0] = cách lập lịch cho i ngày mà ngày thứ i nghỉ
    // dp[i][1] = cách lập lịch cho i ngày mà ngày thứ i đi làm
    // i tính từ 1
    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[1][0] = 1;
    dp[0][0] = 1;

    for(int i = K1; i <= n; ++i) {
        dp[i][0] = dp[i - 1][1];
        for(int k = K1; k <= K2 && k <= i; ++k) {
            dp[i][1] += dp[i - k][0];
        }
    }

    return dp[n][0] + dp[n][1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, K1, K2;
    cin >> n >> K1 >> K2;
    
    cout << numArrangeWorkSchedule(n, K1, K2) << endl;
    cout << numArrangeWorkSchedule2(n, K1, K2) << endl;
}