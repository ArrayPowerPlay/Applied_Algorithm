// Cho trước dãy số a1, a2,...,aN tăng dần
// 1 dãy con = 1 tập con của dãy số đã cho
// Khoảng cách = hiệu nhỏ nhất giữa 2 phần tử liền kề trong dãy con
// Tìm dãy con chứa đúng C phần tử mà khoảng cách là lớn nhất
// Output: khoảng cách lớn nhất

#include <bits/stdc++.h>
using namespace std;

int res;

// check if we can find a subset containing C elements with min distance = d 
bool check(int d, int n, vector<int> &arr, int &C) {
    int cnt = 1;
    int last = arr[0];

    for(int i = 1; i < n; ++i) {
        if(arr[i] - last >= d) {
            ++cnt;
            last = arr[i];
            if(cnt == C) break;
        }
    }

    return cnt >= C;
}

int find_max(int l, int r, int n, vector<int> &arr, int &C) {
    int res = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid, n , arr, C)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // áp dụng thuật toán tham lam
    int n, C;
    // số dãy số của bài toán
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i) {
        cin >> n >> C;
        vector<int> arr(n);
        for(int j = 0; j < n; ++j) cin >> arr[j];

        sort(arr.begin(), arr.end());

        int l = 1, r = (arr[n - 1] - arr[0]) / (C - 1);

        cout << find_max(l, r, n, arr, C) << endl;
    }
}