#include <bits/stdc++.h>
using namespace std;

/*You are given a positive integer n.
A binary string x is valid if all substrings of x of length 2 contain at least one "1".
Return all valid strings with length n, in any order.*/

vector<int> sol;
string s;

bool check(int k, int v) {
    if(k == 0) return true;
    if(sol[k - 1] == 0 && v == 0) return false;
    return true;
}

void Try(int k, const int n, vector<string> & res) {
    for(int v = 0; v <= 1; ++v) {
        if(check(k, v)) {
            sol[k] = v;
            s += to_string(v);
            if(k == n - 1) {
                res.push_back(s);
            } else {
                Try(k + 1, n, res);
            }
            s.pop_back();
        }
    }
}

vector<string> validStrings(int n) {
    vector<string> res;
    sol.resize(n);
    Try(0, n, res);
    return res;
}

int main() {

}