#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& a, int target) {

        int low = 0;
        int high = a.size() - 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            // found target
            if(a[mid] == target)
                return mid;


            // left half is sorted
            if(a[low] <= a[mid]) {

                if(a[low] <= target && target < a[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            // right half is sorted
            else {

                if(a[mid] < target && target <= a[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {

    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    Solution obj;

    int ans = obj.search(nums, target);

    cout << "Index: " << ans << endl;

    return 0;
}

//* Contain Duplicates
class Solution {
public:
    bool search(vector<int>& a, int target) {
        int n = a.size();
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = high - (high - low)/2;
            if(a[mid] == target) return true;
            if (a[low] == a[mid] && a[mid] == a[high]) {
                low++;
                high--;
                continue;
            }
            if(a[low] <= a[mid]){
                if(target >= a[low] && target <= a[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else {
                if(target <= a[high] && target >= a[mid]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};