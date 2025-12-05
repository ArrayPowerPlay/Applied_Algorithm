#include <bits/stdc++.h>     
using namespace std;

/* Có m staff và n task, tìm cách phân task cho m staff sao cho:
- Mỗi task được phân cho đúng 1 staff
- Mỗi staff nhận không quá D task
- c[i][j] là chi phí của việc phân task j cho staff i
In ra chi phí nhỏ nhất 
*/

const int INF = 1e8;
int m, n, D;
// Ma trận chi phí
vector<vector<int>> c;
// Lưu lời giải cục bộ
vector<int> sol;
// Khối lượng task mà mỗi staff phải nhận
vector<int> load;
// Chi phí tính tới thời điểm hiện tại
int curr = 0;
// Chi phí tối thiểu cần tìm
int res = INF;
// Kiểm tra có tồn tại lời giải hay không
bool checkAns = 0;

bool check(int k, int v) {
    if(load[v] + 1 > D) return false;
    return true;
}

// Thử phân task thứ k cho 1 staff nào đó
void Try(int k) {
    if(k == n + 1) {
        int flag = 1;
        for(int i = 1; i <= m; ++i) {
            if(load[i] > D) flag = 0;
        }
        if(flag) {
            res = min(res, curr);
            checkAns = true;
        }
        return;
    }

    for(int v = 1; v <= m; ++v) {
        if(!check(k, v)) continue;
        
        sol[v] = 1;
        curr += c[v][k];
        ++load[v];

        Try(k + 1);

        curr -= c[v][k];
        --load[v];
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n >> D;
    c.resize(m + 1, vector<int>(n + 1));
    sol.assign(n + 1, 0);
    load.assign(m + 1, 0);
    
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> c[i][j];
        }
    }

    Try(1);
    if(!checkAns) cout << -1 << endl;
    else cout << res << endl;
}