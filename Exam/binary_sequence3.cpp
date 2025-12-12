#include <bits/stdc++.h>
using namespace std;

// In ra tất cả các xâu nhị phân không chứa 2 ký tự 1 liên tiếp

vector<int> sol;

bool check(int k, int v) {
    if(k == 1) return true;
    if(sol[k - 1] == 1 && v == 1) return false;
    return true;
}

void Try(int k, int n) {
    if(k == n + 1) {
        for(int t = 1; t <= n; ++t) cout << sol[t];
        cout << endl;
        return;
    }

    for(int v = 0; v <= 1; ++v) {
        if(!check(k, v)) continue;

        sol[k] = v;
        Try(k + 1, n);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    sol.resize(n + 1);
    Try(1, n);
}