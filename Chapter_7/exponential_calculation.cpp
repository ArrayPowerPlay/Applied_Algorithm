#include <bits/stdc++.h>
using namespace std;

// Use divide and conquer to calculate exponential (x^n)

int Pow(int x, int n) {
    if(n == 0) return 1;
    if(n % 2 == 1) return x * Pow(x, n - 1);
    int res = Pow(x, n / 2);
    return res * res;
}

int main() {

}