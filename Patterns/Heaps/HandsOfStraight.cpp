#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // Check if grouping is possible
        if(hand.size() % groupSize != 0) 
            return false;

        map<int, int> count;

        // Count frequency of each card
        for(int card : hand){
            count[card]++;
        }

        // Traverse in sorted order
        for(auto it : count){
            int start = it.first;
            int freq = it.second;

            // If this card is still available
            if(freq > 0){
                // Try to form groups
                for(int i = 0; i < groupSize; i++){
                    if(count[start + i] < freq)
                        return false;

                    count[start + i] -= freq;
                }
            }
        }

        return true;
    }
};