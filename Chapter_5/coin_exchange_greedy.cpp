// Given a set of coins with denominations D1, D2, ..., Dn and a denomination x
// Find the minimum number of coins to exchange for denomination x

#include <bits/stdc++.h>
using namespace std;

// solution using greedy algorithm
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, cnt = 0;
    cin >> n >> x;
    set<int> st;

    int p;
    for(int i = 0; i < n; ++i) {
        cin >> p;
        if(p > 0 && p <= x) st.insert(p);
    }
    
    while(!st.empty()) {
        auto idx = st.upper_bound(x);
        if(idx != st.begin()) {
            --idx;
            int t = *idx;
            ++cnt;
            x -= t;
        } else break;
    }
    
    if(cnt == 0) cout << -1 << endl;
    else cout << cnt << endl;
}
