#include <bits/stdc++.h>
using namespace std;

/* Với 1 cặp xâu, ta đặt + là phép toán ghép xâu
S1 = A
S2 = B
S_n = S_(n - 2) + S_(n - 1)
Yêu cầu: Tính ký tự thứ k trong S_n (chỉ số tính từ 0)*/

int main() {
    string S1, S2;
    long long k;
    cin >> S1 >> S2 >> k;

    const int MAXN = 100;
    vector<long long> len(MAXN + 1);
    len[1] = (long long) S1.size();
    len[2] = (long long) S2.size();

    // Chặn theo k + 1 để so sánh chính xác với k
    const long long LIM = k + 1;

    for(int i = 3; i <= MAXN; ++i) {
        long long sum = len[i - 1] + len[i - 2];
        if(sum > LIM) sum = LIM;
        len[i] = sum;
    }

    // Tìm n nhỏ nhất sao cho len[n] > k
    int n = 2;
    while(n <= MAXN && len[n] <= k) ++n;

    // Chia để trị quy về S[n - 1] hoặc S[n - 2], từ đó lùi về S[1] và S[2]
    while(n > 2) {
        if(len[n - 1] > k) {
            n = n - 1;
        } else {
            k -= len[n - 1];
            n = n - 2;
        }
    }

    char ans = (n == 1) ? S1[k] : S2[k];
    cout << ans << endl;
}