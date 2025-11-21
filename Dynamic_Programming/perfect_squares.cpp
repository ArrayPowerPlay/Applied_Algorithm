#include <bits/stdc++.h>
using namespace std;

/*Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. 
For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.*/ 

int numSquares(int n) {
    vector<int> squares;
    const int INF = 1e8;
    for(int i = 1; i <= n; ++i) {
        if(i * i <= n) squares.push_back(i * i);
        else break;
    }

    // Bài toán trở thành bài toán đổi tiền. Sử dụng các tờ tiền trong vector "squares". Ta cần tìm số tờ tiền nhỏ nhất để đổi
    // được đồng tiền có giá trị n
    vector<int> dp(n + 1, INF);
    // Cần 0 tờ tiền để đổi được tờ có giá trị 0
    dp[0] = 0;
    
    for(int i = 1; i <= n; ++i) {
        for(int num : squares) {
            if(i >= num) {
                dp[i] = min(dp[i], 1 + dp[i - num]);
            }
        }
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << numSquares(n) << endl;
}