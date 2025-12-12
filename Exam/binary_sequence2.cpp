#include <bits/stdc++.h>
using namespace std;

// In ra tất cả chuỗi nhị phân có chứa '111'

string res;
int n;

void Try(int k) {
    if(k == n + 1) {
        if(res.find("111") != string::npos) {
            cout << res << endl;
        }
        return;

    }

    for(int v = 0; v <= 1; ++v) {
        res += to_string(v);
        Try(k + 1);

        res.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    Try(1);
    cout << res << endl;
}
