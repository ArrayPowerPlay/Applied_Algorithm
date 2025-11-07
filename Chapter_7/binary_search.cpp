#include <bits/stdc++.h>
using namespace std;

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

int main() {
    int n;
    int x = 8;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; ++i) cin >> a[i];

    cout << binary_search(a, 0, n - 1, x);
}