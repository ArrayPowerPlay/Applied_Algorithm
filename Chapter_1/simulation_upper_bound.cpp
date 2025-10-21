#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    multiset<int> s;
    string str;

    for(int i = 0; i < n; ++i) {
        cin >> x;
        s.insert(x);
    }

    cin.ignore(100, '\n');

    while(true) {
        getline(cin, str);
        if(str == "#") break;
        x = stoi(str.substr(5));
        auto it = s.upper_bound(x);

        if(it != s.end()) cout << *it << endl;
        else cout << -1 << endl;
    }

}