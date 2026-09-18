/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool check(TreeNode* root, int sum, int target){
        if(root == NULL) return false;
        sum += root->val;
        if (root->left == NULL && root->right == NULL) {
            return sum == target;
        }
        bool left = check(root->left, sum, target);
        bool right = check(root->right, sum, target);
        return left || right;
    }
public:
    bool hasPathSum(TreeNode* root, int target) {
        if(root == NULL) return false;
        return check(root, 0, target);
    }
};