#include <bits/stdc++.h>
using namespace std;

/*Dãy a[i], (i từ 1 đến n) thể hiện doanh thu của cửa hàng từ ngày 1 đến ngày n. Tìm số chuỗi ngày 
(gồm các ngày liên tiếp) có tổng doanh thu không nhỏ hơn doanh thu tối thiểu (D)*/

// Solution 1: prefix sum
int sol(vector<int> &nums, vector<int> &M, const int &D) {
    int len = nums.size();
    int res = 0;

    for(int i = 1; i < len; ++i) {
        for(int j = i; j < len; ++j) {
            if(M[j] - M[i - 1] >= D) {
                ++res;
            }
        }
    }

    return res;
}

// Solution 2: 2 pointers
int sol2(vector<int> &nums, const int &D) {
    const int n = nums.size();
    if(n < 2) return 0;
    int r = 1, sum = 0, res = 0;
    
    for(int l = 1; l < n; ++l) {
        while(r < n && sum < D) {
            sum += nums[r];
            ++r;
        }
        if(sum < D) break;
        res += n - r + 1;
        sum -= nums[l];
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, D;
    cin >> n >> D;
    vector<int> a(n + 1);
    // prefix sum
    vector<int> M(n + 1, 0);

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        M[i] = M[i - 1] + a[i];
    }

    cout << "Solution 1: " << sol(a, M, D) << endl;
    cout << "Solution 2: " << sol2(a, D) << endl;

}