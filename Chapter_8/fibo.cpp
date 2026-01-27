#include <bits/stdc++.h>
using namespace std;

int mem[10000000];

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
    cout << Fibo(n) << endl;
}