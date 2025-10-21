#include <bits/stdc++.h>
using namespace std;

struct Node {
    int L, R;
    int max_val;
};

vector<Node> seg;
vector<int> a;
int n;

// build a node in a segment tree
void build(int idx, int L, int R) {
    seg[idx].L = L;
    seg[idx].R = R;
    
    if(L == R) {
        seg[idx].max_val = a[L];
        return;
    }

    int mid = (L + R) / 2;
    int LC = 2 * idx;
    int RC = 2 * idx + 1;

    build(LC, L, mid);
    build(RC, mid + 1, R);
    seg[idx].max_val = max(seg[LC].max_val, seg[RC].max_val);
    
}

int get_max_from_node(int idx, int i, int j) {
    int L = seg[idx].L;
    int R = seg[idx].R;

    if(i > R || j < L) return INT_MIN;
    // [L, R] lies within [i, j]
    else if(i <= L && j >= R) {
        return seg[idx].max_val;
    } else {
        int LC = 2 * idx;
        int RC = 2 * idx + 1;

        return max(get_max_from_node(LC, i, j), get_max_from_node(RC, i, j));
    }
}

int get_max(int i, int j) {
    return get_max_from_node(1, i, j);
}

void update(int idx, int pos, int value) {
    // update index 'pos' in the array to value 'value'
    int L = seg[idx].L;
    int R = seg[idx].R;

    if(L == R) {
        seg[idx].max_val = value;
    } else {
        int mid = (L + R) / 2;
        int LC = 2 * idx;
        int RC = 2 * idx + 1;

        if(pos <= mid) {
            update(LC, pos, value);
        } else update(RC, pos, value);

        seg[idx].max_val = max(seg[LC].max_val, seg[RC].max_val);
    }

}

int main() {
    int m, i, j;
    string s;
    cin >> n;
    a.resize(n + 1);
    seg.resize(4 * n);

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    build(1, 1, n);

    cin >> m;

    for(int t = 0; t < m; ++t) {
        cin >> s;
        cin >> i >> j;
        if(s == "get-max") {
            cout << get_max(i, j) << endl;
        } else {
            update(1, i, j);
        }
    }
}