#include <bits/stdc++.h>
using namespace std;

int minJump(const int &n, vector<int> &a) {
    int cnt = 0;
    int i = 0;
    while (i < n - 1)
    {
        if(i + a[i] >= n - 1) return ++cnt;

        int max_value = -1;
        int max_idx = i;
        for(int j = i + 1; j <= i + a[i]; ++j) {
            if(max_value < j + a[j]) {
                max_value = j + a[j];
                max_idx = j;
            }
        }
        if(max_idx != i) {
            i = max_idx;
            ++cnt;
        }
        else break;
    }
    return cnt;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        cout << minJump(n, a) << endl;
    }
}