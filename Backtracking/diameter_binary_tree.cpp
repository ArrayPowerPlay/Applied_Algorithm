#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two 
nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int res = 0;

int cntDepth(TreeNode *u) {
    if(u == nullptr) return -1;

    int l = cntDepth(u->left);
    int r = cntDepth(u->right);

    res = max(res, l + r + 2);

    return 1 + max(l, r);
}

int diameterOfBinaryTree(TreeNode *root) {
    if(root == nullptr) return 0;
    cntDepth(root);
    return res;
}

int main() {

}