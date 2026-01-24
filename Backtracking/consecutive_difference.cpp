#include <bits/stdc++.h>
using namespace std;

// Given two integers n and k, return an array of all the integers of length
// n where the difference between every two consecutive digits is k. You may 
// return the answer in any order.

// Note that the integers should not have leading zeros. Integers as 02 and 043
// are not allowed.

vector<int> res;
int curr;
vector<int> sol;

bool check(int idx, int v, int k) {
    if(idx == 1) {
        if(v == 0) return false;
        else return true;
    } else {
        int a = curr % 10;
        if(abs(a - v) != k) return false;
        return true;
    }
}

void dfs(int idx, int k, int n) {
    if(idx == n + 1) {
        res.push_back(curr);
        return;
    }

    for(int v = 0; v <= 9; ++v) {
        if(!check(idx, v, k)) continue;
        curr = curr * 10 + v;
        dfs(idx + 1, k, n);
        curr = curr / 10;
    }
}

vector<int> numsSameConsecDiff(int n, int k) {
    dfs(1, k, n);
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> res = numsSameConsecDiff(n, k);
    for(auto &x : res) cout << x << " ";
}
