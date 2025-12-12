#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const ull MOD = 1e9 + 7;
map<pair<ull, ull>, ull> mem;

// Tính a^b modulo 1e9 + 7

ull pow(ull a, ull b) {
    if(mem[{a, b}] != 0) return mem[{a, b}];

    if(b == 0) return 1;
    if(b == 1) return a;
    ull res;
    if(b & 1) {
        ull e = pow(a, (b - 1) / 2) % MOD;
        res = (a *  e * e) % MOD;
    } else {
        ull e = pow(a, b / 2) % MOD;
        res = (e * e) % MOD;
    }

    mem[{a, b}] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ull a, b;
    cin >> a >> b;
    cout << pow(a, b) << endl;
}