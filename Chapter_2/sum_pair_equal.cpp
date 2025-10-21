#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, res = 0;
    cin >> n >> m;
    vector<int> a(n + 1);
    
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a.begin() + 1, a.end());

    int i = 1;
    int j = n;

    while(i < j) {
        if (a[i] + a[j] == m) {
            res++;
            i++;
            j--;
        }
        else if (a[i] + a[j] < m) i++;
        else j--;
    } 

    cout << res << endl;
}