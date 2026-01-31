#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf 
paths where the sum of the node values in the path equals targetSum. Each path 
should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. 
A leaf is a node with no children.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> res;
vector<int> curr;

void dfs(TreeNode *u, int target) {
    curr.push_back(u->val);

    if(u->left == nullptr && u->right == nullptr) {
        if(target == 0) {
            res.push_back(curr);
        }
        return;
    }

    if(u->left != nullptr) {
        dfs(u->left, target - u->left->val);
        curr.pop_back();
    }
    if(u->right != nullptr) {
        dfs(u->right, target - u->right->val);
        curr.pop_back();
    }
}

vector<vector<int>> pathSum(TreeNode *root, int target) {
    if(root == nullptr) return {};
    dfs(root, target - root->val);
    return res;
}

int main() {

}