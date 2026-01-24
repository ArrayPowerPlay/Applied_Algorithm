#include <bits/stdc++.h>
using namespace std;

// You are given an integer finalSum. Split it into a sum of a maximum number
// of unique positive even integers.

// Return a list of integers that represent a valid split containing a maximum
// number of integers. If no valid split exists for finalSum, return an empty 
// list. You may return the integers in any order.

vector<long long> maximumEvenSplit(long long finalSum) {
    if(finalSum % 2 != 0) return {};
    vector<long long> res;
    for(long long v = 2; v <= finalSum; v += 2) {
        finalSum -= v;
        res.push_back(v);
    }
    if(finalSum > 0) {
        res.back() += finalSum;
    } 
    return res;
}

int main() {
    long long finalSum;
    cin >> finalSum;
    vector<long long> maxSplit = maximumEvenSplit(finalSum);
    for(auto &x : maxSplit) cout << x << " ";
    
}