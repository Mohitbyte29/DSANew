/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        map<int, int> m;
        queue<pair<Node*, int>> q;
        vector<int> ans;
        if(!root)  return ans;
        q.push({root, 0});
        while(!q.empty()){
            Node* t = q.front().first;
            int h = q.front().second;
            q.pop();
            if(!m[h]) m[h] = t->data;
            if(t->left) q.push({t->left, h - 1});
            if(t->right) q.push({t->right, h + 1});
        }
        for(auto x:m){
            ans.push_back(x.second);
        }
        return ans;
    }
};