class Solution {
    unordered_map<long long, int> prefix;
    int dfs(TreeNode* node, long long cur, int target) {
        if (!node) return 0;
        cur += node->val;
        int count = 0;
        auto it = prefix.find(cur - target);
        if (it != prefix.end()) count += it->second;

        prefix[cur]++;
        count += dfs(node->left, cur, target);
        count += dfs(node->right, cur, target);
        prefix[cur]--;   // backtrack

        return count;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;   // empty prefix, so paths starting at root count
        return dfs(root, 0, targetSum);
    }
};