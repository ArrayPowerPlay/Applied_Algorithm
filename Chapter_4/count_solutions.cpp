// count the number of solutions to an integer linear equation
// a1.X1 + a2.X2 + ... + an.Xn = M

#include <bits/stdc++.h>
using namespace std;

int n, m;
int res = 0;
int curr_sum = 0;
vector<int> a, x;

void try_solutions(int k) {
    for(int v = 0; v <= (m - curr_sum) / a[k]; ++v) {
        x[k] = v;
        curr_sum += a[k] * x[k];

        if(k == n) {
            if(curr_sum == m) res++;
        } else {
            try_solutions(k + 1);
        }
        // backtrack
        curr_sum -= a[k] * x[k];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    a.resize(n + 1);
    x.resize(n + 1);

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        m -= a[i];
    }

    try_solutions(1);
    cout << res << endl;
}