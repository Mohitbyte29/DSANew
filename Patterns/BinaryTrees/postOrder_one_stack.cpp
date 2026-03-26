#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;

        if (root == NULL) return postOrder;

        TreeNode* curr = root;
        TreeNode* temp = NULL;
        stack<TreeNode*> st;

        while (curr != NULL || !st.empty()) {

            // Go left as much as possible
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                temp = st.top()->right;

                // If no right child, process node
                if (temp == NULL) {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->val);

                    // Check if we are coming back from right subtree
                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        postOrder.push_back(temp->val);
                    }
                }
                else {
                    // Move to right subtree
                    curr = temp;
                }
            }
        }

        return postOrder;
    }
};