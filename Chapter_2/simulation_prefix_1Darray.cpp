#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, i, j;
    cin >> n;
    vector<int> arr(n + 1);
    vector<int> prefix_sum(n + 1, 0);

    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
        prefix_sum[i] = arr[i] + prefix_sum[i - 1];
    }

    cin >> q;

    for(int k = 0; k < q; ++k) {
        cin >> i >> j;
        cout << prefix_sum[j] - prefix_sum[i - 1] << endl;
    }

}