#include <bits/stdc++.h>
using namespace std;

// Tìm kiếm nhị phân
bool binary_search(const vector<int> &a, int left, int right, int x) {
    while(left <= right) {
        int mid = (left + right) / 2;

        if(a[mid] == x) return true;
        else if(a[mid] < x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

// Tìm kiếm nhị phân trên số nguyên
/*Cho hàm P: {0, 1,..., n - 1} -> {TRUE, FALSE} thỏa mãn:
P(i) = TRUE thì P(j) = TRUE với mọi j > i
Yêu cầu: Tìm j nhỏ nhất sao cho P(j) = TRUE*/
int binary_search(const vector<int> &P, int lo, int hi) {
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        if(P[mid]) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    if(lo == hi && P[hi]) return hi;
    else return -1;         // Không tồn tại j sao cho P(j) = TRUE
}

// Tìm kiếm nhị phân trên số thực
/* P(j) chứa các chỉ số là số thực
Ánh xạ từ số thực sang các giá trị {TRUE, FALSE}
Ta tìm số thực j' rất sát với lời giải đúng j, với sai số trong khoảng
EPS = 2^(-10)*/
double binary_search_real_number(const vector<double> &P, double lo, double hi) {
    double EPS = 2e-10;
    while(hi - lo > EPS) {
        double mid = (hi + lo) / 2.0;
        if(P[mid]) hi = mid;
        else lo = mid;
    }
    return lo;
} 

int main() {
    int n;
    int x = 8;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; ++i) cin >> a[i];

    cout << binary_search(a, 0, n - 1, x);
}