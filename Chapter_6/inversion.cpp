// Đếm số cặp nghịch thế của 1 hoán vị
// Input: dãy số nguyên
// Output: số cặp (i, j) thỏa mãn i < j mà a_i > a_j

#include <bits/stdc++.h>
using namespace std;

vector<int> num;
vector<int> tmp;
int cnt = 0;

// Áp dụng đếm số cặp nghịch thế trong lúc sử dụng mergesort
// Độ phức tạp: O(nlogn) so với cách đếm từng cặp từ trái sang phải O(n2)
void count_and_mergesort(int left, int right) {
    if(left >= right) return;
    int mid = (left + right) / 2;
    count_and_mergesort(left, mid);
    count_and_mergesort(mid + 1, right);

    int i = left, j = mid + 1, k = left;
    while(i <= left && j <= right) {
        if(num[i] <= num[j]) {
            tmp[k++] = num[i++];
        } else {
            tmp[k++] = num[j++];
            cnt += mid - i + 1;
        }
    }
    
    while(i <= left) tmp[k++] = num[i++];
    while(j <= right) tmp[k++] = num[j++];

    for(int t = left; t <= right; ++t) {
        num[t] = tmp[t];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    num.resize(n);
    tmp.resize(n);
    for(int i = 0; i < n; ++i) cin >> num[i];
    count_and_mergesort(0, n - 1);

    cout << cnt << endl;
}