#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void invert(TreeNode* root){
        if(root == NULL) return;
        if(root->left || root->right){
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        if(root->left) invert(root->left);
        if(root->right) invert(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        invert(root);
        return root;
    }
};