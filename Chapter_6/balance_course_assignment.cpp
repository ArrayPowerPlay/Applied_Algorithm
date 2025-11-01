// The department D has m teachers T={1,2,...,m} and n courses C={1,2,...,n}
// Each teacher t∈T has a preference list which is a list of courses he/she can teach
// We know a list of pairs of conflicting two courses that cannot be assigned to the same teacher
// The load of a teacher is the number of courses assigned to her/him
// How to assign n courses to m teachers such that each course assigned to a teacher is in his/her preference list, 
// no two conflicting courses are assigned to the same teacher, and the maximal load is minimal.

// As n and m would be in large scale, we will apply greedy algorithm
#include <bits/stdc++.h>
using namespace std;

int n, m;
const int INF = 1e8;
// prefer[i] = j means teacher i can teach subject j
vector<unordered_set<int>> prefer;
// conflict[i] = j means i and j cannot be taught by the same teacher
vector<vector<int>> conflict;
// number of subjects that a teacher is assigned
vector<int> load;
// canTeachCourse[c] = list of teachers that can teach course c
vector<vector<int>> canTeachCourse;
// list of courses that a teacher has been assigned by the algorithm
vector<unordered_set<int>> assignTeacher;
// rearrange course so that courses with fewer number of teachers can teach
// are prioritized first, if 2 courses can be teached by the same number of teachers,
// we prioritized course that has the most number of conflict with other courses
vector<int> course;

void input() {
    cin >> m >> n;

    // store memory for vectors
    load.assign(m + 1, 0);
    prefer.assign(m + 1, {});
    conflict.assign(n + 1, {});
    canTeachCourse.assign(n + 1, {});
    assignTeacher.assign(m + 1, {});
    course.resize(n + 1);

    for(int i = 1; i <= n; ++i) course[i] = i;

    int k, c;
    for(int i = 1; i <= m; ++i) {
        cin >> k;

        for(int j = 0; j < k; ++j) {
            cin >> c;
            prefer[i].insert(c);
            canTeachCourse[c].push_back(i);
        }
    }

    int num_conflicts;
    cin >> num_conflicts;
    int a, b;
    for(int j = 0; j < num_conflicts; ++j) {
        cin >> a >> b;
        conflict[a].push_back(b);
        conflict[b].push_back(a);
    }
}

// check if teacher t can teach cource c
bool check(int t, int c) {
    // check if teacher t has c in his/her preferences
    if(prefer[t].find(c) == prefer[t].end()) return false;
    // check if teacher t has taught any subject cc that conflicts with c or not
    for(int cc : conflict[c]) {
        if(assignTeacher[t].find(cc) != assignTeacher[t].end()) {
            return false;
        }
    }

    return true;
}

int greedySolution() {
    sort(course.begin() + 1, course.end(), [&](int a, int b) {
        int degree_a = canTeachCourse[a].size();
        int degree_b = canTeachCourse[b].size();

        if(degree_a != degree_b) {
            return degree_a < degree_b;
        }

        return conflict[a].size() > conflict[b].size();
    });

    // assign each course in vector 'course' into each teacher, 
    // prioritize teacher with fewer loads
    for(int i = 1; i <= n; ++i) {
        int c = course[i];

        int bestLoad = INF;
        int bestT = -1;
        // list of teachers 
        for(int t : canTeachCourse[c]) {
            if(!check(t, c)) continue;
            if(bestLoad > load[t]) {
                bestLoad = load[t];
                bestT = t;
            }
        }

        if(bestT == -1) return -1;
        assignTeacher[bestT].insert(c);
        ++load[bestT];
    }

    int maxload = 0;
    for(int i = 1; i <= m; ++i) {
        maxload = max(maxload, load[i]);
    }

    return maxload;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        input();
        cout << greedySolution() << endl;
    }
}