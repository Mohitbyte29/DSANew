#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
     int data;
     Node* next;
     Node* back;

     Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
     }

     Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
     }
};

Node* convert2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* back = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, back);
        back->next = temp;
        back = back->next;
    }
    return head;
}



int main(){
    vector<int> arr = {3, 6, 21, 7, 4};
    Node* head = convert2LL(arr);
    // cout<<head->data;
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}