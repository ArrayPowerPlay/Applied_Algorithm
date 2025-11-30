#include <bits/stdc++.h>
using namespace std;

vector<int> mem;

int Fibo(int n) {
    if(n <= 2) return 1;
    if(mem[n] != -1) return mem[n];
    int res = Fibo(n - 1) + Fibo(n - 2);
    mem[n] = res;
    return res;
}

int main() {
    int n;
    cin >> n;
    mem.assign(n + 1, -1);
    cout << Fibo(n) << endl;
}