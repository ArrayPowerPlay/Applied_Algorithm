#include <bits/stdc++.h>
using namespace std;

// The power of an integer x is defined as the number of steps needed to transform x into 1 using the following steps:
// if x is even then x = x / 2
// if x is odd then x = 3 * x + 1
// For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).

// Given three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by the power value in 
// ascending order, if two or more integers have the same power value sort them by ascending order.

// Return the kth integer in the range [lo, hi] sorted by the power value.

unsigned int getPower(int x) {
    unsigned int res = 0;
    while(x != 1) {
        if(x % 2 == 0) x /= 2;
        else x = x * 3 + 1;
        ++res;
    }
    return res;
}

int getKth(int lo, int hi, int k) {
    vector<int> a(hi - lo + 1);
    for(int i = 0; i < hi - lo + 1; ++i) {
        a[i] = lo + i;
    }
    sort(a.begin(), a.end(), [&](auto &a, auto &b){
        unsigned int aa = getPower(a), bb = getPower(b);
        if(aa != bb) return aa < bb;
        else return a < b;
    });
    return a[k - 1];
}

int main() {
    
}