class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int depth = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                 if (node->left == NULL && node->right == NULL)
                    return depth;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};