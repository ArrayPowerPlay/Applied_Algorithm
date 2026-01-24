#include<bits/stdc++.h>
using namespace std;

// Bài toán tìm kiếm xâu mẫu: Cho văn bản T là 1 chuỗi ký tự (độ dài N)
// lấy từ 1 bảng cho trước và 1 xâu mẫu P (độ dài M). Hãy tìm tất cả các
// vị trí xuất hiện của P trong T

// Ví dụ: T = abacbacacbac
//        P = acba
// Code bên dưới áp dụng thuật toán Boyer Moore

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string T, P;
    cin >> T >> P;
    int n = T.size(), m = P.size();
    vector<int> appear;
    vector<int> last(256, -1);

    for(int i = 0; i < m; ++i) {
        last[P[i]] = i;
    }

    int i = 0;
    while(i <= n - m) {
        int j = m - 1;
        while(j >= 0) {
            if(T[i + j] == P[j]) --j;
            else break;
        }

        if(j == -1) {
            appear.push_back(i);
            i += m;
        } else {
            int shift = j - last[T[i + j]];
            i += max(1, shift);
        }
    }
    for(auto &x : appear) cout << x << " ";
}