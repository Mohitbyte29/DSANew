#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> bottomView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<pair<TreeNode*, int>> q;
        map<int, int> mpp;
        q.push({root, 0});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            if(mpp.find(level) == mpp.end()) mpp[level] = node->val; 
            if(node->left) q.push({node->left, level + 1});
            if(node->right) q.push({node->right, level + 1});
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;