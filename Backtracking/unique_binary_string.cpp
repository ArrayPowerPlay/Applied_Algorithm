#include <bits/stdc++.h>
using namespace std;

// Given an array of strings nums containing n unique binary strings each
// of length n, return a binary string of length n that does not appear in
// nums. If there are multiple answers, you may return any of them.

string str, res;
bool found = false;

void dfs(int n, unordered_set<string> &st) {
    if(found) return;

    if(str.size() == n) {
        if(st.count(str)) {
            res = str;
            found = true;
        }
        return;
    }

    for(char c : {'0', '1'}) {
        str.push_back(c);
        dfs(n, st);
        if(found) return;
        str.pop_back();
    }
}

string findDifferentBinaryString(vector<string> &nums) {
    unordered_set<string> st(nums.begin(), nums.end());
    int n = nums.size();
    dfs(n, st);
    return res;
}

int main() {

}