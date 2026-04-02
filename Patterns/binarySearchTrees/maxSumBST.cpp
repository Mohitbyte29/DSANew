#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class NodeValue {
public:
    int minNode, maxNode, maxSum;
    NodeValue(int minNode, int maxNode, int maxSum)
        : minNode(minNode), maxNode(maxNode), maxSum(maxSum) {}
};

class Solution {
private:
    int ans = 0;

    NodeValue helper(TreeNode* root) {
        if (!root)
            return NodeValue(INT_MAX, INT_MIN, 0);

        auto left  = helper(root->left);
        auto right = helper(root->right);

        if (left.maxNode < root->val && right.minNode > root->val) {
            int sum = left.maxSum + right.maxSum + root->val;
            ans = max(ans, sum);
            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                sum
            );
        }

        return NodeValue(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));
    }

public:
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};

// Helper to build tree from level-order array (-1 = null)
TreeNode* buildTree(vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front(); q.pop();
        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    // Example 1: [1,4,3,2,4,2,5,-1,-1,-1,-1,-1,-1,4,6] → Output: 20
    vector<int> nodes1 = {1,4,3,2,4,2,5,-1,-1,-1,-1,-1,-1,4,6};
    TreeNode* root1 = buildTree(nodes1);
    Solution sol1;
    cout << "Example 1: " << sol1.maxSumBST(root1) << endl;  // 20

    // Example 2: [4,3,-1,1,2] → Output: 2
    vector<int> nodes2 = {4,3,-1,1,2};
    TreeNode* root2 = buildTree(nodes2);
    Solution sol2;
    cout << "Example 2: " << sol2.maxSumBST(root2) << endl;  // 2

    // Example 3: [-4,-2,-5] → Output: 0
    vector<int> nodes3 = {-4,-2,-5};
    TreeNode* root3 = buildTree(nodes3);
    Solution sol3;
    cout << "Example 3: " << sol3.maxSumBST(root3) << endl;  // 0

    return 0;
}
// ```

// **Output:**
// ```
// Example 1: 20
// Example 2: 2
// Example 3: 0