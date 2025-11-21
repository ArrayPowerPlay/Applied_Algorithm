#include <bits/stdc++.h>
using namespace std;

/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day 
in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0*/

const int INF = 1e8;

int maxProfit(vector<int> &prices) {
    int len = prices.size();
    if(len < 2) return 0;

    int res = 0;
    int cheapest = INF;
    
    for(int i = 0; i < len; ++i) {
        int curr = prices[i];
        if(curr < cheapest) {
            cheapest = curr;
        } else {
            int diff = curr - cheapest;
            res = max(res, diff);
        }
    }
    return res;
}


int main() {

}