// Cho một tập các số nguyên A = {a_1, a_2,..., a_n}. Tổng của một tập hợp là tổng tất cả các phần tử 
// thuộc tập hợp đó. Phân hoạch A thành 3 tập sao cho chênh lệch giữa tổng của tập lớn nhất và tổng
// của tập nhỏ nhất là nhỏ nhất.

// Input: 
// Dòng thứ 1: n 
// Dòng thứ 2: a_1, a_2,..., a_n 
// Output: 
// Dòng 1: các chỉ số của các phần tử thuộc tập thứ 1 
// Dòng 2: các chỉ số của các phần tử thuộc tập thứ 2 
// Dòng 3: các chỉ số của các phần tử thuộc tập thứ 3 
// Dòng 4: khoảng cách nhỏ nhất (lưu ý các chỉ số đều tính từ 0)

// Ý tưởng:
// Tạo nghiệm ban đầu bằng greedy (xét theo giá trị: phần tử lớn nhất được xếp vào tập có tổng nhỏ nhất)
// Local search cải thiện nghiệm
// Bước 1: Chuyển 1 phần tử từ tập lớn nhất -> tập nhỏ nhất
// Bước 2: Đổi 1 phần tử giữa tập lớn nhất và tập nhỏ nhất
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calcDiff(ll s0, ll s1, ll s2) {
    long long mx = max({s0, s1, s2});
    long long mn = min({s0, s1, s2});
    return mx - mn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    // GREED SEARCH
    vector<pair<ll, int>> v;
    for(int i = 0; i < n; ++i) v.push_back({a[i], i});
    sort(v.begin(), v.end(), [](auto &x, auto &y) {
        return x.first > y.first;
    });

    vector<int> sets[3];
    ll sums[3] = {0, 0, 0};

    for(auto &p : v) {
        int minSumIdx = 0;
        if(sums[1] < sums[minSumIdx]) minSumIdx = 1;
        if(sums[2] < sums[minSumIdx]) minSumIdx = 2;

        ll value = p.first;
        int idx = p.second;
        sums[minSumIdx] += value;
        sets[minSumIdx].push_back(idx);
    }

    // Trả về chỉ số của tập lớn nhất và tập nhỏ nhất hiện tại
    auto getMaxMinGroup = [&]() {
        int gmax = 0, gmin = 0;
        for(int i = 1; i < 3; ++i) {
            if(sums[gmax] < sums[i]) gmax = i;
            if(sums[gmin] > sums[i]) gmin = i;
        }
        return pair<int, int>(gmax, gmin);
    };

    // LOCAL SEARCH
    long long bestDiff = calcDiff(sums[0], sums[1], sums[2]);
    // Giới hạn số lần lặp
    const int MAX_IT = 3000;

    for(int it = 0; it < MAX_IT; ++it) {
        auto [gmax, gmin] = getMaxMinGroup();
        ll currDiff = calcDiff(sums[0], sums[1], sums[2]);

        // STEP 1: thử move từ tập lớn nhất sang tập nhỏ nhất
        int bestMoveIdx = -1;
        int bestMoveDiff = currDiff;
        for(int i = 0; i < (int)sets[gmax].size(); ++i) {
            int idx = sets[gmax][i];
            ll value = a[idx];
            ll n0 = sums[0], n1 = sums[1], n2 = sums[2];

            if(gmax == 0) n0 -= value;
            if(gmax == 1) n1 -= value;
            if(gmax == 2) n2 -= value;

            if(gmin == 0) n0 += value;
            if(gmin == 1) n1 += value;
            if(gmin == 2) n2 += value;

            ll diff = calcDiff(n0, n1, n2);
            if(diff < bestMoveDiff) {
                bestMoveDiff = diff;
                bestMoveIdx = i;
            }
        }

        if(bestMoveIdx != -1) {
            int idx = sets[gmax][bestMoveIdx];
            ll value = a[idx];
            sets[gmax].erase(sets[gmax].begin() + bestMoveIdx);
            sets[gmin].push_back(idx);
            sums[gmax] -= value;
            sums[gmin] += value;
            
            bestDiff = bestMoveDiff;
            // Nếu kết quả cải thiện thì chuyển luôn sang vòng lặp tiếp theo
            continue;
        }

        // STEP 2: swap phần tử giữa tập lớn nhất và tập nhỏ nhất
        const int LIMIT = 50;
        int limA = min((int)sets[gmax].size(), LIMIT);
        int limB = min((int)sets[gmin].size(), LIMIT);

        int moveIdxA = -1, moveIdxB = -1;
        ll bestSwapDiff = currDiff;

        for(int i = 0; i < limA; ++i) {
            int idxA = sets[gmax][i];
            ll vA = a[idxA];
            for(int j = 0; j < limB; ++j) {
                int idxB = sets[gmin][j];
                ll vB = a[idxB];

                ll n0 = sums[0], n1 = sums[1], n2 = sums[2];
                if(gmax == 0) n0 = n0 - vA + vB;
                if(gmax == 1) n1 = n1 - vA + vB;
                if(gmax == 2) n2 = n2 - vA + vB;

                if(gmin == 0) n0 = n0 + vA - vB;
                if(gmin == 1) n1 = n1 + vA - vB;
                if(gmin == 2) n2 = n2 + vA - vB;

                ll curr = calcDiff(n0, n1, n2);
                if(curr < bestSwapDiff) {
                    bestSwapDiff = curr;
                    moveIdxA = i;
                    moveIdxB = j;
                }
            }
        }

        if(moveIdxA != -1) {
            int idxA = sets[gmax][moveIdxA];
            int idxB = sets[gmin][moveIdxB];

            swap(sets[gmax][moveIdxA], sets[gmin][moveIdxB]);

            ll vA = a[idxA];
            ll vB = a[idxB];

            sums[gmax] = sums[gmax] - vA + vB;
            sums[gmin] = sums[gmin] + vA - vB;
            bestDiff = bestSwapDiff;
        } else break;           // Dừng khi việc lặp không làm cải thiện nghiệm
    }

    // In ra kết quả
    for(int g = 0; g < 3; ++g) {
        for(int i = 0; i < (int)sets[g].size(); ++i) {
            cout << sets[g][i] << " ";
        }
        cout << endl;
    }
    cout << bestDiff << endl;
    return 0;
}