#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getDepth(TreeNode *node) {
    if (!node) {
        return 0;
    }
    return 1 + max(getDepth(node->left), getDepth(node->right));
}

TreeNode *lcaDeepestLeaves(TreeNode *root) {
    int lefD = getDepth(root->left);
    int rigD = getDepth(root->right);
    if (lefD == rigD) {
        return root;
    } else if (lefD > rigD) {
        return lcaDeepestLeaves(root->left);
    } else {
        return lcaDeepestLeaves(root->right);
    }
}