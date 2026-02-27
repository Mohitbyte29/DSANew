Brute
class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int len = 0, maxLen = 0;
        int zeros;
            for(int i = 0; i<n; i++){
                zeros = 0;
                for(int j = i; j<n; j++){
                    if(arr[j] == 0){
                        zeros++;
                    }
                    if(zeros <= k){
                        len = j - i + 1;
                        maxLen = max(len, maxLen);
                    }
                    else{
                        break;
                    }
                }
            }
            return maxLen;
    }
};

Better
class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int len = 0, maxLen = 0;
        int zeros = 0;
        int l = 0, r = 0;
        for(int r = 0; r<n; r++){
                if(arr[r] == 0){
                    zeros++;
                }
            while(zeros > k){   
                if(arr[l] == 0){
                    zeros--;
                }
                l++;
            }
                int len = r - l + 1;
                maxLen = max(len, maxLen);
        }
        return maxLen;  
    }
};

Best
class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int len = 0, maxLen = 0;
        int zeros = 0;
        int l = 0, r = 0;
        while(r < n){
            if(arr[r] == 0){
                zeros++;
            }
            if(zeros > k){
                if(arr[l] == 0){
                    zeros--;
                }
                l++;
            }
            if(zeros <= k){
                len = r - l + 1;
            }
            maxLen = max(maxLen, len);
            r++;
        }
        return maxLen;  
    }
};