#include <bits/stdc++.h>
using namespace std;

// You are the manager of a basketball team. For the upcoming tournament, you want to choose the team 
// with the highest overall score. The score of the team is the sum of scores of all the players in the team.

// However, the basketball team is not allowed to have conflicts. A conflict exists if a younger player has a
// strictly higher score than an older player. A conflict does not occur between players of the same age.

// Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith 
// player, respectively, return the highest overall score of all possible basketball teams.

int bestTeamScore(vector<int> &scores, vector<int> &ages) {
    int n = scores.size();
    vector<pair<int, int>> par(n);
    for(int i = 0; i < n; ++i) {
        par[i].first = ages[i];
        par[i].second = scores[i];
    }
    // sort theo tuổi, cùng tuổi sort theo score
    sort(par.begin(), par.end(), [](auto &a, auto &b) {
        if(a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });
    // dp[i] là tổng điểm lớn nhất của cả team khi chọn người cuối cùng là người i (i tính từ chỉ số 0)
    vector<int> dp(n, 0);
    int res = par[0].second;

    for(int i = 0; i < n; ++i) {
        int score = par[i].second;
        dp[i] = score;
        if(i == 0) continue;
        else {
            for(int j = 0; j < i; ++j) {
                if(par[j].second <= score) dp[i] = max(dp[i], dp[j] + score);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> ages(n);
    vector<int> scores(n);
    for(int i = 0; i < n; ++i) {
        cin >> ages[i] >> scores[i];
    }
    cout << bestTeamScore(scores, ages);
}