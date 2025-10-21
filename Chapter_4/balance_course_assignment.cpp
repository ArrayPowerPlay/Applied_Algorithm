// inputs and constraints
// m teachers T = {1, 2,..., m} and n subjects C = {1, 2,..., n}
// teacher t in T has a list of subjects that he/she can teach
// overlapping subjects cannot be teached by the same teacher
// each teacher has workload, which is the number of subjects
// that he/she is assigned

// objective
// minimize workload of teachers
// output
// minimum of maximum workload (max workload of teachers) or -1 (if cannot arrange timetable)

#include <bits/stdc++.h>
using namespace std;

// m: number of teachers
// n: number of subjects
// k: number of pairs of subject that are overlapped with each other
int m, n, k;
int min_max_workload = INT_MAX;
// sol[i] = j if teacher j teach subject i
vector<int> sol;
// workload[i] = workload of teacher i
vector<int> workload;
// prefer[i][j] = 1 => teacher j can teach subject i
vector<vector<int>> prefer;
// conflict[i][j] = 1 means a teacher cannot teach both subject i and j 
vector<vector<int>> conflict;
// check if we can find a suitable timetable or not
bool check_valid = false;

// check if teacher j can teach subject k
bool check(int j, int k) {
    if(prefer[k][j] == 0) return false;
    // check previous class
    for(int i = 1; i <= k - 1; ++i) {
        if(sol[i] == j && conflict[i][k] == 1) return false;
    }

    return true;
}

// select teacher for subject k
void try_arrange(int k) {
    for(int v = 1; v <= m; ++v) {
        if(check(v, k)) {
            sol[k] = v;
            ++workload[v];

            if(k == n) {
                check_valid = true;
                int maxload = 0;
                for(int i = 1; i <= m; ++i) {
                    maxload = max(maxload, workload[i]);
                }
                min_max_workload = min(maxload, min_max_workload);
            } else {
                if(workload[v] < min_max_workload) {
                    try_arrange(k + 1);
                }
            }
            // backtrack
            --workload[v];

        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t, x, a, b;
    cin >> m >> n;
    prefer.assign(n + 1, vector<int>(m + 1, 0));
    conflict.assign(n + 1, vector<int>(n + 1, 0));
    sol.resize(n + 1);
    workload.resize(m + 1);

    for(int j = 1; j <= m; ++j) {
        cin >> t;
        for(int i = 0; i < t; ++i) {
            cin >> x;
            prefer[x][j] = 1;
        }
    }

    cin >> k;

    for(int i = 0; i < k; ++i) {
        cin >> a >> b;
        conflict[a][b] = 1;
        conflict[b][a] = 1;
    }

    try_arrange(1);

    if(!check_valid) {
        cout << - 1 << endl;
        return 0;
    }

    cout << min_max_workload << endl;
}