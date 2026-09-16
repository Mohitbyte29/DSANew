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
public:
    int findBottomLeftValue(TreeNode* root) {
        int curr = -1;
        int value = -1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int index = q.front().second;
            if(index > curr){
                curr = index;
                value = node->val;
            }
            q.pop();
            if(node->left){
                q.push({node->left, index + 1});
            }
            if(node->right){
                q.push({node->right, index + 1});
            }
        }
        return value;
    }
};