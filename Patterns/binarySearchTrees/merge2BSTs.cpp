#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* tempNode = st.top();
        st.pop();
        pushAll(tempNode->right);
        return tempNode->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};