class Solution {
    void dfs(TreeNode* root, int target, vector<int>& path, vector<vector<int>>& ans){
            if(root == NULL) return;
            path.push_back(root->val);
            target -= root->val;
            if (root->left == NULL && root->right == NULL) {
                if (target == 0) {
                    ans.push_back(path);
                }
            }
            dfs(root->left, target, path, ans);
            dfs(root->right, target, path, ans);
            path.pop_back();
        }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> result;
        vector<vector<int>> ans;
        dfs(root, targetSum, result, ans);
        return ans;
    }
};