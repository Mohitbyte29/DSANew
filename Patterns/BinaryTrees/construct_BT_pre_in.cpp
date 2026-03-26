#include <vector>
#include <map>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;

        // Store inorder indices
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1,
                     inMap);
    }

private:
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    map<int, int>& inMap) {

        // Base case
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        // Root from preorder
        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = inMap[root->val];       // index in inorder
        int numsLeft = inRoot - inStart;     // nodes in left subtree

        // Build left subtree
        root->left = build(preorder,
                           preStart + 1,
                           preStart + numsLeft,
                           inorder,
                           inStart,
                           inRoot - 1,
                           inMap);

        // Build right subtree
        root->right = build(preorder,
                            preStart + numsLeft + 1,
                            preEnd,
                            inorder,
                            inRoot + 1,
                            inEnd,
                            inMap);

        return root;
    }
};