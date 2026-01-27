#include <bits/stdc++.h>
using namespace std;

int n, Q;
vector<int> sol;
vector<int> a;
vector<vector<int>> d;
int minPath;

void dfs() {
    
}

void greedy() {

}

int main() {
    cin >> n >> Q;
    a.resize(n + 1);
    d.resize(n + 1, vector<int>(n + 1));

    for(int i = 1; i <= n; ++i) cin >> a[i];

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            cin >> d[i][j];
        }
    }

    if(n <= 15) {
        dfs();
    } else {
        greedy();
    }


}