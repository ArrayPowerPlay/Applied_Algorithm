#include <bits/stdc++.h>
using namespace std;

// You are given a 0-indexed string pattern of length n consisting of the characters 'I'
// meaning increasing and 'D' meaning decreasing.

// A 0-indexed string num of length n + 1 is created using the following conditions:

// num consists of the digits '1' to '9', where each digit is used at most once.
// If pattern[i] == 'I', then num[i] < num[i + 1].
// If pattern[i] == 'D', then num[i] > num[i + 1].
// Return the lexicographically smallest possible string num that meets the conditions.

string curr, res;
vector<bool> visited;
bool found = false;

void dfs(int k, int n, string &pattern) {
    if(found) return;

    if(k == n + 1) {
        found = true;
        res = curr;
        return;
    }

    for(int v = 1; v <= 9; ++v) {
        if(visited[v]) continue;
        if(pattern[k - 1] == 'I' && v < (curr.back() - '0')) continue;
        if(pattern[k - 1] == 'D' && v > (curr.back() - '0')) continue;
        visited[v] = 1;
        curr.push_back(v + '0');
        dfs(k + 1, n, pattern);
        // Backtrack
        if(found) return;
        visited[v] = 0;
        curr.pop_back();
    }
}

string smallestNumber(string pattern) {
    visited.assign(10, false);
    int n = pattern.size();
    int i = 0, start = 1;
    while(i < n) {
        if(pattern[i] == 'D') {
            ++start;
        } else break;
        ++i;
    }
    visited[start] = true;
    curr.push_back(start + '0');
    dfs(1, n, pattern);
    return res;
}

int main() {
    string s;
    cin >> s;
    string res = smallestNumber(s);
    cout << res << endl;
}
