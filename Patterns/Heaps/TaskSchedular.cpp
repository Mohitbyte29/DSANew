#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;

        // Count frequency
        for(char t : tasks){
            counts[t]++;
        }

        // Max heap
        priority_queue<int> pq;
        for(auto c : counts){
            pq.push(c.second);
        }

        int result = 0;

        while(!pq.empty()){
            int time = 0;
            vector<int> tmp;

            // Process one cycle of size (n + 1)
            for(int i = 0; i < n + 1; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();

                    if(freq - 1 > 0)
                        tmp.push_back(freq - 1);

                    time++;
                }
            }

            // Push remaining tasks back
            for(int t : tmp){
                pq.push(t);
            }

            // If heap empty → only add actual time
            // Else → full cycle (n+1)
            result += pq.empty() ? time : n + 1;
        }

        return result;
    }
};