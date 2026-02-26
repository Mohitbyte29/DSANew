#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node *convertLL(vector<int> &arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node *head = convertLL(arr);
    cout<<head;
    cout<< head->next<<endl;
    cout<< head->data<<endl;
    Node *temp = head;
    cout<<temp->data;
    while(temp){
        cout<<temp->data<<" ";
        cout<<temp->next<<" ";
        temp= temp->next;
    }
    return 0;
}