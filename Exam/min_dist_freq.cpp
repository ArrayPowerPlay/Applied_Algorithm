#include <bits/stdc++.h>
using namespace std;

/* Cho mảng f với f[i] là tần suất xuất hiện của phần tử thứ i trong một
mảng nào đó. Ta cần chia mảng thành K khoảng sao cho sự sai khác về tần
suất giữa các khoảng là nhỏ nhất. Một cách chia K được đặc trưng bởi K - 1
chỉ số 1 <= i_1 < i_2 < ... < i_(K - 1) <= n trong đó:
- Khoảng 1 bao gồm các giá trị thứ 1 tới thứ i_1 - 1
- Khoảng 2 bao gồm các giá trị thứ i_1 tới thứ i_2 - 1
...
- Khoảng K bao gồm các giá trị thứ i_(K - 1) tới n
Output: khoảng cách giữa khoảng có tần suất lớn nhất và khoảng có tần suất
nhỏ nhất
*/

// Với D bất kỳ, để maxSum - minSum <= D thì ta tìm chỉ số k nằm trong tập {0, pre[i],..., pre[n]}
// sao cho T <= sum <= T + D với sum là tổng đoạn con bất kỳ trong K đoạn con có thể chia được
// Tức là T <= pre[R] - pre[L] <= T + D
bool check(const int &n, vector<int> &f, vector<int> &pre, const int &K, const int &D) {
    // Thử mọi ứng viên T = pre[i]
    for(int i = 0; i <= n; i++) {
        int T = pre[i];
        int lo = T;
        int hi = T + D;

        int segments = 0;
        int pos = 0;
        bool ok = true;

        // Bắt đầu từ chỉ số pos, ta tìm chỉ số R sao cho T <= pre[R] - pre[pos] <= T + D
        while(pos < n) {
            // Lval = pre[pos] + T
            // Hval = pre[pos] + T + D
            int Lval = pre[pos] + lo;
            int Hval = pre[pos] + hi;
            // Tham lam: tìm R lớn nhất sao cho pre[R] <= Hval
            int R = upper_bound(pre.begin(), pre.end(), Hval) - pre.begin() - 1;
            if(R <= pos) {
                ok = false;
                break;
            }

            if(pre[R] < Lval || pre[R] > Hval) {
                ok = false;
                break;
            }

            ++segments;
            pos = R;

            if(segments > K) {
                ok = false;
                break;
            }
        }

        if(ok && segments == K) {
            return true;
        }
    }
    return false;
}

int minDistFreq(const int &n, vector<int> &f, vector<int>& pre, const int &K) {
    if(K == 1) return 0;

    // Áp dụng binary search trên độ lệch tối đa cho phép
    int lo = 0;
    int hi = accumulate(f.begin(), f.end(), 0);
    int ans = hi;

    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(check(n, f, pre, K, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, K;
    cin >> n >> K;
    vector<int> f(n + 1);
    // Prefix sum
    vector<int> pre(n + 1, 0);

    for(int i = 1; i <= n; ++i) cin >> f[i];
    for(int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + f[i];
    }

    cout << minDistFreq(n, f, pre, K) << endl;
}
