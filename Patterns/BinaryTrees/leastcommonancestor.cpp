#include <iostream>
using namespace std;

// Definition for binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // Base case
        if (root == NULL || root == p || root == q) {
            return root;
        }

        // Search in left and right subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If one side is NULL → return the other
        if (left == NULL) {
            return right;
        }
        else if (right == NULL) {
            return left;
        }

        // If both sides are NOT NULL → current node is LCA
        return root;
    }
};