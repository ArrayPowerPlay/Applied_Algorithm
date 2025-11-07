#include <bits/stdc++.h>
using namespace std;

vector<int> tmp;

void mergesort(vector<int> &a, int left, int right) {
    if(left >= right) return;
    int mid = (left + right) / 2;

    mergesort(a, left, mid);
    mergesort(a, mid + 1, right);

    int i = left, j = mid + 1, k = left;
    while(i <= mid && j <= right) {
        if(a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
    }

    while(i <= mid) tmp[k++] = a[i++];
    while(j <= right) tmp[k++] = a[j++];

    for(int t = left; t <= right; ++t) {
        a[t] = tmp[t];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    tmp.resize(n);

    for(int i = 0; i < n; ++i) cin >> a[i];
    
    mergesort(a, 0, n - 1);

    for(int i = 0; i < n; ++i) cout << a[i] << " ";
}