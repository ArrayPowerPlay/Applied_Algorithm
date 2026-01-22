#include <bits/stdc++.h>
using namespace std;

int n1, n2, n, L, M, P, max_value = INT_MIN;
vector<int> a;
vector<vector<int>> conflict;
vector<int> sol;
int curr = 0, res = -1, cnt_tech = 0, cnt_sale = 0;

void input() {
    cin >> n1 >> n2;
    n = n1 + n2;
    a.resize(n + 1);
    sol.resize(n + 1);

    for(int i = 1; i <= n1 + n2; ++i) {
        cin >> a[i];
        if(max_value < a[i]) max_value = a[i];
    }

    cin >> L >> M >> P;
    conflict.assign(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= P; ++i) {
        int a, b;
        cin >> a >> b;
        conflict[a][b] = 1;
        conflict[b][a] = 1;
    }
}

bool check(int k, int v) {
    for(int i = 1; i < k; ++i) {
        if(conflict[v][sol[i]] == 1) return false;
    }
    return true;
}

void Try(int k, int last) {
    if(cnt_sale >= M && cnt_tech >= M) {
        if(curr > res) res = curr;
    }

    if(k > L) return;
    // Pruning
    if(L - k + 1 + cnt_sale < M) return;
    if(L - k + 1 + cnt_tech < M) return;
    if(curr + (L - k + 1) * max_value < res) return;

    for(int v = last + 1; v <= n; ++v) {
        if(!check(k, v)) continue;
        sol[k] = v;
        if(v <= n1) ++cnt_tech;
        else ++cnt_sale;
        curr += a[v];

        Try(k + 1, v);
        // Backtrack
        if(v <= n1) --cnt_tech;
        else --cnt_sale;
        curr -= a[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    Try(1, 0);
    cout << res << endl;
}