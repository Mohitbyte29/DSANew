/* Structure of binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        // code here
        queue<Node*> q;
        vector<int> ans;
        if(root == NULL) return ans;
        q.push(root);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            while(node){
                ans.push_back(node->data);
                if(node->left != NULL){
                    q.push(node->left);
                }
                node = node->right;
            }
        }
        return ans;
    }
};