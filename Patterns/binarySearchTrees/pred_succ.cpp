//! Approach 1 — Inorder traversal

#include <bits/stdc++.h>
using namespace std;

// Node definition
struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// ── Step 1: collect sorted nodes ──────────────────────
void inorder(Node* root, vector<Node*>& res) {
    if (!root) return;
    inorder(root->left, res);
    res.push_back(root);
    inorder(root->right, res);
}

// ── Step 2: find predecessor & successor ──────────────
vector<Node*> findPreSuc(Node* root, int key) {
    vector<Node*> res;
    inorder(root, res);

    Node* pre = nullptr;
    Node* suc = nullptr;

    for (int i = 0; i < (int)res.size(); i++) {
        if (res[i]->data < key)
            pre = res[i];      // keep updating → closest below

        if (res[i]->data > key && suc == nullptr)
            suc = res[i];      // first above key = successor
    }

    vector<Node*> ans;
    if (pre) ans.push_back(pre);   // only push valid nodes
    if (suc) ans.push_back(suc);
    return ans;
}

// ── Driver ────────────────────────────────────────────
int main() {
    Node* root = new Node(14);
    root->left  = new Node(2);
    root->right = new Node(16);
    root->left->left   = new Node(1);
    root->left->right  = new Node(10);
    root->right->left  = new Node(15);
    root->right->right = new Node(20);
    root->left->right->left  = new Node(6);
    root->left->right->right = new Node(12);
    root->right->right->left  = new Node(19);
    root->right->right->left->left = new Node(17);

    int key = 21;
    auto ans = findPreSuc(root, key);

    cout << "Key: " << key << "\n";
    if (ans.size() >= 1) cout << "Predecessor: " << ans[0]->data << "\n";
    else                  cout << "Predecessor: None\n";
    if (ans.size() == 2)  cout << "Successor  : " << ans[1]->data << "\n";
    else                  cout << "Successor  : None\n";

    return 0;
}

//! Approach 2 --> BST Optimal

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// ── BST property: O(h) time, O(1) space ───────────────
vector<Node*> findPreSuc(Node* root, int key) {
    Node* pre = nullptr;
    Node* suc = nullptr;
    Node* curr = root;

    while (curr) {
        if (curr->data == key) {
            // Predecessor = rightmost in left subtree
            if (curr->left) {
                Node* tmp = curr->left;
                while (tmp->right) tmp = tmp->right;
                pre = tmp;
            }
            // Successor = leftmost in right subtree
            if (curr->right) {
                Node* tmp = curr->right;
                while (tmp->left) tmp = tmp->left;
                suc = tmp;
            }
            break;

        } else if (curr->data < key) {
            pre  = curr;           // candidate predecessor
            curr = curr->right;

        } else {
            suc  = curr;           // candidate successor
            curr = curr->left;
        }
    }

    vector<Node*> ans;
    if (pre) ans.push_back(pre);
    if (suc) ans.push_back(suc);
    return ans;
}

// ── Driver ────────────────────────────────────────────
int main() {
    Node* root = new Node(14);
    root->left  = new Node(2);
    root->right = new Node(16);
    root->left->left   = new Node(1);
    root->left->right  = new Node(10);
    root->right->left  = new Node(15);
    root->right->right = new Node(20);
    root->left->right->left  = new Node(6);
    root->left->right->right = new Node(12);
    root->right->right->left  = new Node(19);
    root->right->right->left->left = new Node(17);

    // Test 1: key = 21 (no successor)
    auto ans = findPreSuc(root, 21);
    cout << "Key: 21\n";
    cout << "Predecessor: " << (ans.size()>=1 ? to_string(ans[0]->data) : "None") << "\n";
    cout << "Successor  : " << (ans.size()==2 ? to_string(ans[1]->data) : "None") << "\n\n";

    // Test 2: key = 10 (exact match exists)
    ans = findPreSuc(root, 10);
    cout << "Key: 10\n";
    cout << "Predecessor: " << (ans.size()>=1 ? to_string(ans[0]->data) : "None") << "\n";
    cout << "Successor  : " << (ans.size()==2 ? to_string(ans[1]->data) : "None") << "\n";

    return 0;
}