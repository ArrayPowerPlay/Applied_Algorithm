// Cho một đường thẳng và các đoạn trên đường thẳng đó
// Tìm tập con của X chỉ chứa các đoạn đôi một không giao nhau
// và có lực lượng lớn nhất
// Output: in ra số lực lượng của tập X

#include <bits/stdc++.h>
using namespace std;

struct Segment {
    int begin;
    int end;
};

// apply greedy algorithm
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Segment> seg(n);

    int x, y;
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        seg[i].begin = x;
        seg[i].end = y;
    }

    sort(seg.begin(), seg.end(), [](const Segment &a, const Segment &b) {
        return a.end < b.end;
    });

    int i = 0;
    int last = -1;
    int cnt = 0;
    while(i < n) {
        Segment &a = seg[i];
        if(a.begin > last) {
            ++cnt;
            last = a.end;
        } else ++i;
    }

    cout << cnt << endl;
}