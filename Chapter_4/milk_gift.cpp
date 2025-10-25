// A milk company wants to thank its customers, the company prints on each carton of fresh milk 
// a natural number taken from a list of different secret natural numbers given in advance 
// If consumers collect a set of fresh milk cartons so that the natural numbers in these cartons
// are different and their sum is greater than or equal to the year the company was founded, 
// they will be given an additional carton of fresh milk 
// Find how many different ways can you exchange the gift
// Two ways are called different if the set of natural numbers on the cartons of milk are different

#include <bits/stdc++.h>
using namespace std;

int n;
int year;
vector<int> num;
int cnt = 0;

void Try(int k, int curr_sum) {
    if(k > n) {
        if(curr_sum >= year) {
            cnt++;
        }
        return;
    }

    if(curr_sum >= year) {
        cnt += (1 << (n + 1 - k));
        return;
    }

    Try(k + 1, curr_sum);
    Try(k + 1, curr_sum + num[k]);
}

int main() {
    cin >> n;
    num.resize(n + 1);

    for(int i = 1; i <= n; ++i) {
        cin >> num[i];
    }

    cin >> year;

    Try(1, 0);
    cout << cnt << endl;
}