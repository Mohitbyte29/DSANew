#include <vector>
#include <unordered_map>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;

        // store inorder indices
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return build(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1,
                     inMap);
    }

private:
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int postStart, int postEnd,
                    unordered_map<int, int>& inMap) {

        // Base case
        if (postStart > postEnd || inStart > inEnd)
            return NULL;

        // Root comes from LAST in postorder
        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        // Build left subtree
        root->left = build(inorder,
                           inStart,
                           inRoot - 1,
                           postorder,
                           postStart,
                           postStart + numsLeft - 1,
                           inMap);

        // Build right subtree
        root->right = build(inorder,
                            inRoot + 1,
                            inEnd,
                            postorder,
                            postStart + numsLeft,
                            postEnd - 1,
                            inMap);

        return root;
    }
};