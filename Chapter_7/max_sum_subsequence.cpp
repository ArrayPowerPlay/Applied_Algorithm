#include <bits/stdc++.h>
using namespace std;

// find max of a subsequence of a sequence of integer 
// using divide and conquer

const int INF = 1e8;

int maxSumSeqDC(vector<int> &a, int left, int right) {
    if(left == right) return a[left];

    int mid = (left + right) / 2;
    int maxSumL = maxSumSeqDC(a, left, mid);
    int maxSumR = maxSumSeqDC(a, mid + 1, right);
    
    int maxL = -INF;
    int sumL = 0;
    for(int i = mid; i >= left; --i) {
        sumL += a[i];
        maxL = max(sumL, maxL);
    }

    int maxR = -INF;
    int sumR = 0;
    for(int i = mid + 1; i <= right; ++i) {
        sumR += a[i];
        maxR = max(maxR, sumR);
    }

    int maxSumM = maxL + maxR;
    return max(max(maxSumL, maxSumR), maxSumM);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << maxSumSeqDC(a, 0, n - 1) << endl;
}