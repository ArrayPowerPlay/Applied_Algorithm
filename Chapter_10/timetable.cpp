#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> duration;
vector<int> num_students;
vector<int> capacity;
vector<int> load;
// Pair of start time, duration 
vector<vector<pair<int, int>>> available;
// Đánh dấu used[room_id][period_index] để biết tiết học đó đã có người dùng chưa
bool used[15][100];
int min_maxload = INT_MAX;

void input() {
    cin >> n;
    duration.resize(n + 1);
    num_students.resize(n + 1);
    string s;

    for(int i = 1; i <= n; ++i) {
        cin >> s >> duration[i] >> num_students[i];
    }

    cin >> m;
    capacity.resize(m + 1);
    load.assign(m + 1, 0);
    available.resize(m + 1);
    for(int i = 1; i <= m; ++i) {
        cin >> s;
        int t;
        cin >> capacity[i] >> t;
        for(int j = 1; j <= t; ++j) {
            int x, y;
            cin >> x >> y;
            available[i].push_back({x, y});
        }
    }
}

bool check(int k, int v) {
    if(num_students[k] > capacity[v]) return false;
    return true;
}

void Try(int k) {
    // Prunning
    int curr = *max_element(load.begin() + 1, load.end());
    if(curr >= min_maxload) return;

    // Điều kiện dừng
    if(k > n) {
        min_maxload = min(min_maxload, curr);
        return;
    }

    for(int v = 1; v <= m; ++v) {
        if(!check(k, v)) continue;

        for(int i = 0; i < available[v].size(); ++i) {
            if(used[v][i]) continue;

            if(duration[k] <= available[v][i].second) {
                used[v][i] = true;
                load[v] += duration[k];
                Try(k + 1);
                // Backtrack
                load[v] -= duration[k];
                used[v][i] = false;
            }
        }   
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    Try(1);
    cout << min_maxload << endl;
}