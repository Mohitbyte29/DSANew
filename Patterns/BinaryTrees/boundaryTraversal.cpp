/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  bool isLeaf(Node* root){
            return (!root->left && !root->right);
        }
        
    void addLeftBoundary(Node* root, vector<int>& res){
        Node* cur = root->left;
        while(cur){
            if(!isLeaf(cur)){
                res.push_back(cur->data);
            }
            if(cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }
    
    void addRightBoundary(Node* root, vector<int>& res){
        Node* cur = root->right;
        vector<int> temp;
        while(cur){
            if(!isLeaf(cur)){
                temp.push_back(cur->data);
            }
            if(cur->right) cur = cur->right;
            else cur = cur->left;
        }
        int n = temp.size();
        for(int i = n - 1; i >= 0; i--){
            res.push_back(temp[i]);
        }
    }
    
    void addLeafNodes(Node* root, vector<int>& res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left) addLeafNodes(root->left, res);
        if(root->right) addLeafNodes(root->right, res);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> res;
        if(root == NULL) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        addLeftBoundary(root, res);
        addLeafNodes(root, res);
        addRightBoundary(root, res);
        return res;
    }
};