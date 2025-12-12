#include <bits/stdc++.h>
using namespace std;

// Find the common subset of A and B having highest cardinality

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int j = 0; j < m; ++j) cin >> b[j];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0, res = 0;

    while(i < n && j < m) {
        if(a[i] < b[j]) ++i;
        else if (a[i] > b[j]) ++j;
        else {
            ++res;
            ++i;
            ++j;
        }
    }

    cout << res << endl;

}