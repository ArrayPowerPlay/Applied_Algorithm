#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    string str;
    set<int> s;
    cin >> n;
    
    for(int i = 0; i < n; ++i) {
        cin >> x;
        s.insert(x);
    }

    cin.ignore();

    while(true) {
        getline(cin, str);
        int len = str.size();

        if(str == "#") break;
        if(str.find("insert") == 0) {
            x = stoi(str.substr(7));
            s.insert(x);
        } else if(str.find("min_greater_equal") == 0) {
            x = stoi(str.substr(18));
            auto it = s.lower_bound(x);

            if(it != s.end()) cout << *it << endl;
            else cout << "NULL" << endl;
        } else if(str.find("min_greater") == 0) {
            x = stoi(str.substr(12));
            auto it = s.upper_bound(x);

            if(it != s.end()) cout << *it << endl;
            else cout << "NULL" << endl;
        } else {
            x = stoi(str.substr(7));
            s.erase(x);
        }
    }
}