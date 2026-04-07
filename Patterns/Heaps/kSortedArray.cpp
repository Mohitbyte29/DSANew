//! Brute
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        // code here.
        vector<int> sorted(arr, arr + n);
        sort(sorted.begin(), sorted.end());
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(arr[i] == sorted[j]){
                    if(abs(i - j) > k) return "No";
                    break;
                }
            }
        }
        return "Yes";
    }
};

// Better
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        
        // Step 1: Copy and sort array
        vector<int> sorted(arr, arr + n);
        sort(sorted.begin(), sorted.end());
        
        // Step 2: Map value -> queue of indices
        unordered_map<int, queue<int>> mpp;
        
        for(int i = 0; i < n; i++){
            mpp[sorted[i]].push(i);
        }
        
        // Step 3: Check distance
        for(int i = 0; i < n; i++){
            int correctIndex = mpp[arr[i]].front();
            mpp[arr[i]].pop();
            
            if(abs(i - correctIndex) > k)
                return "No";
        }
        
        return "Yes";
    }
};