#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  
  void swap(vector<int> &arr, int i, int j){
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
  }
  
  void Heapify(vector<int> &arr, int index, int N){
      int largest = index;
      int left = 2 * index + 1;
      int right = 2 * index + 2;

      if(left < N && arr[left] > arr[largest]){
          largest = left;
      }

      if(right < N && arr[right] > arr[largest]){
          largest = right;
      }

      if(largest != index){
          swap(arr, largest, index);
          Heapify(arr, largest, N);
      }
  }
  
  void convertMinToMaxHeap(vector<int> &arr, int N) {
      for(int i = N/2 - 1; i >= 0; i--){
          Heapify(arr, i, N);
      }
  }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 2};
    int N = arr.size();

    Solution obj;
    obj.convertMinToMaxHeap(arr, N);

    cout << "Max Heap array: ";
    for(int x : arr){
        cout << x << " ";
    }

    return 0;
}