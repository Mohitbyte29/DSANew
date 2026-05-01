// Better 
class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        vector<int> c(m + n);
        int i = 0, j = 0, k = 0;
        while(i < m && j < n){
            if(a[i] <= b[j]){
                c[k] = a[i];
                i++;
                k++;
            }
            else if(a[i] > b[j]){
                c[k] = b[j];
                j++;
                k++;
            }
        }
        while(i < m){
            c[k] = a[i];
            i++;
            k++;
        }
        while(j < n){
            c[k] = b[j];
            j++;
            k++;
        }
        a = c;
    }
};

//! Best
class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;

        while(i >= 0 && j >= 0){
            if(a[i] > b[j]) a[k--] = a[i--];
            else a[k--] = b[j--];
        }       
        while(j >= 0){
            a[k--] = b[j--];
        }
    }
};
