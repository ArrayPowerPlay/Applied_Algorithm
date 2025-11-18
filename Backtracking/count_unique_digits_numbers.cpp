// Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10^n

#include <bits/stdc++.h>
using namespace std;

vector<int> visited;
int res = 0;

// Solution 1: using backtracking
void backtrack(int k, int n) {
    ++res;

    if(k == n) return;

    for(int i = 0; i <= 9; ++i) {
        if(k == 0 && i == 0) continue;
        if(visited[i]) continue;
        visited[i] = 1;

        backtrack(k + 1, n);

        visited[i] = 0;
    }
}

int countNumbersWithUniqueDigits(int n) {
    if(n == 0) return 1;
    visited.assign(10, 0);
    backtrack(0, n);
    return res;
}

// Solution 2: using formula
int countNumbersWithUniqueDigits2(int n) {
    if(n == 0) return 1;
    int res = 10;
    int num_unique = 9;
    int num_available = 9;

    for(int i = 2; i <= n; ++i) {
        num_unique *= num_available;
        res += num_unique;
        --num_available;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; 
    cin >> n;
    cout << countNumbersWithUniqueDigits(n) << endl;
}