#include <iostream>
using namespace std;
#include <vector>

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }

private:
    TreeNode* build(vector<int>& preorder, int &i, int bound) {
        if (i == preorder.size() || preorder[i] > bound)
            return NULL;

        TreeNode* root = new TreeNode(preorder[i++]);

        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);

        return root;
    }
};