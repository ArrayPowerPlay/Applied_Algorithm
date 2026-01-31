#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a binary tree, return all root-to-leaf paths in any order.
A leaf is a node with no children.

Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

string s;
vector<string> res;
vector<int> curr;

void dfs(TreeNode *u) {
    curr.push_back(u->val);

    if(u->left == nullptr && u->right == nullptr) {
        for(int i = 0; i < curr.size(); ++i) {
            s = s + to_string(curr[i]) + (i == curr.size() - 1 ? "" : "->");
        }
        res.push_back(s);
        s = "";
        return;
    }

    if(u->left != nullptr) {
        dfs(u->left);
        curr.pop_back();
    }
    if(u->right != nullptr) {
        dfs(u->right);
        curr.pop_back();
    }
}

vector<string> binaryTreePaths(TreeNode *root) {
    if(root == nullptr) return {};
    dfs(root);
    return res;
}

int main() {

}