#include <bits/stdc++.h>
using namespace std;

/*
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths
from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., 
there is a directed edge from node i to node graph[i][j]).
*/

vector<int> curr;
vector<vector<int>> res;

void dfs(int u, int n, vector<bool> &visited, vector<vector<int>> &graph) {
    if(u == n - 1) {
        res.push_back(curr);
        return;
    }

    for(int v : graph[u]) {
        if(visited[v]) continue;
        visited[v] = true;
        curr.push_back(v);
        dfs(v, n, visited, graph);
        visited[v] = false;
        curr.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    curr.push_back(0);
    dfs(0, n, visited, graph);
    return res;
}

int main() {

}