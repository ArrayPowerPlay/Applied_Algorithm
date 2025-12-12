#include <bits/stdc++.h>
using namespace std;

// Given n jobs J = {1, 2,..., n}. Each job i has a deadline d[i] and a associated profit
// p[i] if the job is finished before the deadline. Every job takes a single unit of time.
// The minimum possible deadline for any job is 1. No more than one job can be executed at
// a time. Select and schedule a subset of jobs of J such that the total profit is maximal

// Output: total profit

struct Job {
    int d;
    int p;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, sum = 0;
    cin >> n;
    vector<Job> jobs(n + 1);
    vector<int> visited(n + 1, 0);

    for(int i = 1; i <= n; ++i) {
        cin >> jobs[i].d >> jobs[i].p;
    }

    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b) {
         return a.p > b.p;
    });

    for(auto &job : jobs) {
        for(int t = job.d; t >= 1; --t) {
            if(!visited[t]) {
                visited[t] = 1;
                sum += job.p;
                break;
            }
        }
    }

    cout << sum << endl;
}
