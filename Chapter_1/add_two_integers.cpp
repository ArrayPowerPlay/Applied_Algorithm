#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ull a, b, sum;
    cin >> a >> b;
    ull a1 = a/10;
    ull a2 = a%10;
    ull b1 = b/10;
    ull b2 = b%10;
    ull res = a1 + b1 + (a2 + b2)/10;

    if(res > 0) {
        cout << res << (a2 + b2)%10 << endl;
    } else {
        cout << (a2 + b2)%10 << endl;
    }


    return 0;
}