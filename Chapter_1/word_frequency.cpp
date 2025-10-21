#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> m;
    string s, word;

    while(getline(cin, s)) {
        istringstream iss(s);
        while(iss >> word) {
            m[word]++;
        }
    }

    for(auto t : m) {
        cout << t.first << " " << t.second << endl;
    }
}