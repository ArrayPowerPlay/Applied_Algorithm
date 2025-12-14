#include <bits/stdc++.h>
using namespace std;

/*There is a survey that consists of n questions where each question's answer is either 0 (no) or 1 (yes).

The survey was given to m students numbered from 0 to m - 1 and m mentors numbered from 0 to m - 1. 
The answers of the students are represented by a 2D integer array students where students[i] is an integer array
that contains the answers of the ith student (0-indexed). The answers of the mentors are represented by a 2D integer
array mentors where mentors[j] is an integer array that contains the answers of the jth mentor (0-indexed).
Each student will be assigned to one mentor, and each mentor will have one student assigned to them. The compatibility
score of a student-mentor pair is the number of answers that are the same for both the student and the mentor.

For example, if the student's answers were [1, 0, 1] and the mentor's answers were [0, 0, 1], then their compatibility score is 2 because only the second and the third answers are the same.
You are tasked with finding the optimal student-mentor pairings to maximize the sum of the compatibility scores.

Given students and mentors, return the maximum compatibility score sum that can be achieved.*/

int compatibilityScore(vector<int> a, vector<int> b) {
    int res = 0;
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] == b[i]) res++;
    }
    return res;
}

const int INF = 1e9;
int maxScore = -INF;
int score = 0;
vector<int> visited;
vector<int> sol;

void Try(int k, const int &m, vector<vector<int>> &students, vector<vector<int>> &mentors) {
    for(int v = 0; v < m; ++v) {
        if(visited[v]) continue;
        
        sol[k] = v;
        visited[v] = 1;
        int add = compatibilityScore(students[k], mentors[v]);
        score += add;
        if(k == m - 1) {
            maxScore = max(maxScore, score);
        } else {
            Try(k + 1, m, students, mentors);
        }
        visited[v] = 0;
        score -= add;
        
    }
}

int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors) {
    int m = students.size();
    visited.assign(m, 0);
    sol.resize(m);
    Try(0, m, students, mentors);
    return maxScore;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    
}
