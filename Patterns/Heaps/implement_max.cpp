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
            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = 2 * index + 2;
            if(leftChildIndex < heapSize && heap[leftChildIndex] > heap[largest]){
                largest = leftChildIndex;
            }
            if(rightChildIndex < heapSize && heap[rightChildIndex] > heap[largest]){
                largest = rightChildIndex;
            }
            if(largest != index){
                swap(index, largest);
                Heapify(largest);
            }
        }

        void buildTree(){
            for(int index = heapSize/2 - 1; index >= 0; index--){
                Heapify(index);
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
    int arr[] = {10, 5, 20, 6, 11};
    int n = 5;
    MyHeap heap(arr, n);
    heap.buildTree();
    heap.printTree();
    return 0;
}
