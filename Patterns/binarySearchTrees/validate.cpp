#include <climits>
#include <iostream>


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    bool solve(TreeNode* root, long minVal, long maxVal) {
        if (!root) return true;

        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }

        return solve(root->left, minVal, root->val) &&
               solve(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};