#include <iostream>
using namespace std;

// Definition for a binary tree node
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        // If root itself needs to be deleted
        if (root->val == key) {
            return helper(root);
        }

        TreeNode* curr = root;

        while (curr != NULL) {
            if (key < curr->val) {
                if (curr->left && curr->left->val == key) {
                    curr->left = helper(curr->left);
                    break;
                } else {
                    curr = curr->left;
                }
            } else {
                if (curr->right && curr->right->val == key) {
                    curr->right = helper(curr->right);
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }

        return root;
    }

    // Handles deletion logic
    TreeNode* helper(TreeNode* root) {
        // Case 1: No left child
        if (root->left == NULL) {
            return root->right;
        }
        // Case 2: No right child
        else if (root->right == NULL) {
            return root->left;
        }

        // Case 3: Both children exist
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;

        return root->left;
    }

    // Find rightmost node in left subtree
    TreeNode* findLastRight(TreeNode* root) {
        while (root->right != NULL) {
            root = root->right;
        }
        return root;
    }
};