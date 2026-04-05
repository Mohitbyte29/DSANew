#include <iostream>
using namespace std;

class MyHeap{
    public:
        int* heap;
        int heapCapacity;
        int heapSize;
        int* arr;

        MyHeap(int arr[], int cap){
            heapCapacity = cap;
            heapSize = cap;
            heap = new int[heapCapacity];
            for(int i = 0; i<cap; i++){
                heap[i] = arr[i];
            }
        }


        void swap(int i, int j){
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
        }

        void Heapify(int index){
            int largest = index;
            int left = 2*index + 1;
            int right = 2*index + 2;
            if(left < heapSize && heap[left] > heap[largest]){
                largest = left;
            }
            if(right < heapSize && heap[right] > heap[largest]){
                largest = right;
            }
            if(largest != index){
                swap(largest, index);
                Heapify(largest);
            }
        }

        void buildTree(){
            for(int i = heapSize/2 - 1; i >= 0; i--){
                Heapify(i);
            }
        }

        void printTree(){
            for(int i = 0; i<heapSize; i++){
                cout<<heap[i]<<", ";
            }
            cout<<endl;
        }

};

int main(){
    int arr[] = {10, 20, 30, 15, 5, 18};
    int n = 6;
    MyHeap heap(arr, n);
    heap.buildTree();
    heap.printTree();
    return 0;
}
