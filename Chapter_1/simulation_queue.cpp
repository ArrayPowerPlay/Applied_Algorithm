// Perform a sequence of operations over a queue, each element is an integer

#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    string s;

    while(true) {
        getline(cin, s);
        if(s == "#") break;
        if(s == "POP") {
            if(!q.empty()) {
                cout << q.front() << endl;
                q.pop();
            } else cout << "NULL" << endl;
        } else {
            int x = stoi(s.substr(5, s.size() - 5));
            q.push(x);
        }
    }
}

