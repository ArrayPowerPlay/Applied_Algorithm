// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses

#include <bits/stdc++.h>
using namespace std;

// open_cnt: number of open parentheses being added in the string
// close_cnt: number of close parentheses being added in the string
void back_track(int open_cnt, int close_cnt, int n, string& cur, vector<string>& res) {
    //
    if(open_cnt == n && close_cnt == n) {
        res.push_back(cur);
        return;
    }
    if(open_cnt < n) {
        cur.push_back('(');
        back_track(open_cnt + 1, close_cnt, n, cur, res);
        cur.pop_back();
    }
    if(close_cnt < open_cnt) {
        cur.push_back(')');
        back_track(open_cnt, close_cnt + 1, n, cur, res);
        cur.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> res;
    string s;
    // diff between open and close parentheses
    back_track(0, 0, n, s, res);

    for(auto c : res) cout << c << endl;
}
