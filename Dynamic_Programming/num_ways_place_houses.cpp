#include <bits/stdc++.h>
using namespace std;

// There is a street with n * 2 plots, where there are n plots on each side of the street. 
// The plots on each side are numbered from 1 to n. On each plot, a house can be placed.

// Return the number of ways houses can be placed such that no two houses are adjacent to each other
// on the same side of the street. Since the answer may be very large, return it modulo 109 + 7.

// Note that if a house is placed on the ith plot on one side of the street, a house can also be placed
// on the ith plot on the other side of the street.

const int MOD = 1e9 + 7;
typedef long long ll;

// Xây dựng cách xếp cho mỗi bên (do mỗi bên độc lập với nhau), sau đó nhân lại
// để được cách xếp tổng hợp
ll f(int n) {
    if(n == 0) return 1;
    if(n == 1) return 2;
    n = n % MOD;
    ll a = 1, b = 2;
    for(int i = 2; i <= n; ++i) {
        ll c = (a + b) % MOD;
        a = b;
        b = c;
    }
    return b;
}

ll countHousePlacements(int n) {
    ll fib = f(n) % MOD;
    ll a = fib / MOD;
    ll b = fib % MOD;
    ll aa = (a * a) % MOD;
    ll ab = (a * b) % MOD;
    ll bb = (b * b) % MOD;
    return (aa + (2 * ab) % MOD + bb) % MOD;

}

int main() {

}