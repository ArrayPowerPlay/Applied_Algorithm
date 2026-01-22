// Cho một tập các số nguyên A = {a_1, a_2,..., a_n}. Tổng của một tập hợp là tổng tất cả các phần tử 
// thuộc tập hợp đó. Phân hoạch A thành 3 tập sao cho chênh lệch giữa tổng của tập lớn nhất và tổng
// của tập nhỏ nhất là nhỏ nhất.

// Input: 
// Dòng thứ 1: n 
// Dòng thứ 2: a_1, a_2,..., a_n 
// Output: 
// Dòng 1: các chỉ số của các phần tử thuộc tập thứ 1 
// Dòng 2: các chỉ số của các phần tử thuộc tập thứ 2 
// Dòng 3: các chỉ số của các phần tử thuộc tập thứ 3 
// Dòng 4: khoảng cách nhỏ nhất (lưu ý các chỉ số đều tính từ 0)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
}