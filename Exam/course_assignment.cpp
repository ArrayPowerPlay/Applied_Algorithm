#include <bits/stdc++.h>
using namespace std;

/*Cần tìm cách phân bổ lớp cho mỗi giảng viên sao cho khối lượng giảng dạy
lớn nhất giữa các giảng viên là nhỏ nhất
Output: khối lượng giảng dạy lớn nhất giữa các giảng viên*/

const int INF = 1e8;
// Số giảng viên và số lớp học
int m, n;
// Số tín chỉ của mỗi môn học
vector<int> crd;
// Số lớp tối thiếu mà mỗi giảng viên phải dạy
vector<int> lb;
// conflict[i][j] = 1 tức là hai lớp i và j không thể được dạy bởi cùng 1 giảng viên
vector<vector<int>> conflict;
// prefer[i][j] = 1 tức là giảng viên i có thể dạy môn học j
vector<vector<int>> prefer;
// Khối lượng tín chỉ mà mỗi giảng viên được phân
vector<int> load;
// sol[i] = j tức lớp i được phân cho giảng viên j
vector<int> sol;
// Số lớp mà mỗi giảng viên đang được phân
vector<int> numClass;
// output đầu ra
int minMaxLoad = INF;

// Kiểm tra xem có thể phân lớp k cho giảng viên i được không
bool check(int k, int i) {
    if(!prefer[i][k]) return false;
    for(int j = 1; j < k; ++j) {
        if(conflict[j][k] && sol[j] == i) return false;
    }
    return true;
}

// Tìm cách phân lớp thứ k cho một giảng viên nào đó
void Try(int k) {
    for(int i = 1; i <= m; ++i) {
        if(!check(k, i)) continue;
        if(lb[i] - numClass[i] > n - k + 1) return;
            
        sol[k] = i;
        load[i] += crd[k];
        ++numClass[i];

        if(k == n) {
            int maxLoad = 0;
            int flag = 1;
            for(int j = 1; j <= m; ++j) {
                if(numClass[j] < lb[j]) flag = 0;
                maxLoad = max(maxLoad, load[j]);
            }
            // Chỉ cập nhật đáp án khi mọi giảng viên đều đạt số lớp tối thiểu
            if(flag) minMaxLoad = min(minMaxLoad, maxLoad);
            
        } else Try(k + 1);

        // Backtrack
        load[i] -= crd[k];
        --numClass[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n;
    load.assign(m + 1, 0);
    sol.assign(n + 1, 0);
    numClass.assign(m + 1, 0);

    prefer.resize(m + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= m; ++i) {
        int p;
        cin >> p;
        for(int j = 1; j <= p; ++j) {
            int h;
            cin >> h;
            prefer[i][h] = 1;
        }
    }

    crd.resize(n + 1);
    for(int i = 1; i <= n; ++i) cin >> crd[i];
    
    lb.resize(m + 1);
    for(int i = 1; i <= m; ++i) cin >> lb[i];

    int k;
    cin >> k;
    conflict.assign(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= k; ++i) {
        int x, y;
        cin >> x >> y;
        conflict[x][y] = 1;
        conflict[y][x] = 1;
    }

    Try(1);
    if(minMaxLoad == INF) cout << -1 << endl;      // Không tồn tại lời giải
    else cout << minMaxLoad << endl;
}
