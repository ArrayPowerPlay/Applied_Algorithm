#include <bits/stdc++.h>
using namespace std;

// Cho một dãy a_1, a_2,..., a_n. Một dãy con liên tiếp là dãy (a_i, a_(i + 1),..., a_j)
// Ta cần tìm dãy con liên tiếp có tổng không vượt quá Q
// Output: độ dài lớn nhất của dãy con liên tiếp thỏa mãn

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, Q;
    cin >> n >> Q;
    vector<int> a(n + 1);

    for(int i = 1; i <= n; ++i) cin >> a[i];

    const int INF = 1e9;
    int l = 1, sum = 0, res = -INF;

    for(int r = 1; r <= n; ++r) {
        sum += a[r];
        while(sum > Q) {
            sum -= a[l];
            ++l;
        }
        res = max(res, r - l + 1);
    }

    if(res == -INF) cout << -1 << endl;
    else cout << res << endl;
}
