#include <bits/stdc++.h>
using namespace std;

// You are given an integer array cookies, where cookies[i] denotes the number
// of cookies in the ith bag. You are also given an integer k that denotes the
// number of children to distribute all the bags of cookies to. All the cookies
// in the same bag must go to the same child and cannot be split up.

// The unfairness of a distribution is defined as the maximum total cookies 
// obtained by a single child in the distribution.

// Return the minimum unfairness of all distributions.

vector<long long> numCookies;
int unfairness = INT_MAX;

void dfs(int idx, int k, int n, vector<int> &cookies) {
    if(*max_element(numCookies.begin() + 1, numCookies.end()) > unfairness) return;

    if(idx == n) {
        int curr = *max_element(numCookies.begin() + 1, numCookies.end());
        unfairness = min(unfairness, curr);
        return;
    }

    for(int v = 1; v <= k; ++v) {                     
        numCookies[v] += cookies[idx];
        dfs(idx + 1, k, n, cookies);
        numCookies[v] -= cookies[idx];
        if(numCookies[v] == 0) break;
    }
}

int distributeCookies(vector<int> &cookies, int k) {
    int n = cookies.size();
    numCookies.assign(k + 1, 0);
    sort(cookies.rbegin(), cookies.rend());
    dfs(0, k, n, cookies);
    return unfairness;
}

int main() {

}