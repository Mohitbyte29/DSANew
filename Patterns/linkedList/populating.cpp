/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;
        Node* leftMost = root;
        while(leftMost != NULL){
            Node* current = leftMost;
            Node* nextLevel = NULL;
            Node* prev = NULL;
            while(current != NULL){
            if(current->left != NULL){
                if(prev == NULL){
                    nextLevel = current->left;
                }
                else{
                    prev->next = current->left;
                }
                prev = current->left;
            }
            if(current->right != NULL){
                if(prev == NULL){
                    nextLevel = current->right;
                }
                else{
                    prev->next = current->right;
                }
                prev = current->right;
            }
            current = current->next;
        }
        if(prev != NULL){
            prev->next = NULL;
        }
        leftMost = nextLevel;
        }
        return root;
    }
};