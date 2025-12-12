#include <bits/stdc++.h>
using namespace std;

// Tìm số chuỗi nhị phân có độ dài n mà không chứa s trong đó
// VD: n = 3, s = 10 => output: 4

int res = 0;
int n;
string s;
string sol;

bool check(int v, int len) {
    string str = sol + to_string(v);
    int nlen = str.size();
    if(nlen >= len) {
        if(str.substr(nlen - len, len) == s) {
            return false;
        }
        else return true;
    }
    return true;
}

void Try(int k, int len) {
    for(int v = 0; v <= 1; ++v) {
        if(!check(v, len)) {
            continue;
        }

        sol += to_string(v);
        if(k == n) {
            ++res;
        } else Try(k + 1, len);

        sol.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s;
    int len = s.size();
    Try(1, len);
    cout << res << endl;
}
