#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    string str;
    int x;
    
    while(true) {
        getline(cin, str);
        if(str == "#") break;
        if(str.find("PUSH") == 0) {
            x = stoi(str.substr(5));
            s.push(x);
        } else {
            if(!s.empty()) {
                x = s.top();
                s.pop();
                cout << x << endl;
            } else cout << "NULL" << endl;
        }
    }
}