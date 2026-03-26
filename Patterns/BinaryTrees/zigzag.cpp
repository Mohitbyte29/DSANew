#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == NULL) return result;

        queue<TreeNode*> que;
        que.push(root);

        bool leftToRight = true;

        while (!que.empty()) {
            int size = que.size();
            vector<int> row(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                // decide index based on direction
                int index = (leftToRight) ? i : (size - 1 - i);
                row[index] = node->val;

                if (node->left)
                    que.push(node->left);

                if (node->right)
                    que.push(node->right);
            }

            result.push_back(row);

            // flip direction
            leftToRight = !leftToRight;
        }

        return result;
    }
};