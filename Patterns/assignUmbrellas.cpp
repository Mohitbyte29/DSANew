class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int n = rain.size();
        vector<string> ans(n, "None");
        int alice = 0, bob = 0;
        for(int i = 0; i < n; i++){
            bool aliceNeeds = (i < n - 1 && rain[i] == 1 && rain[i + 1] == 1);
            bool bobNeeds = (rain[i] == 1);
             if (!aliceNeeds && !bobNeeds) {
                ans[i] = "None";
            }
            else if (aliceNeeds && !bobNeeds) {
                ans[i] = "Alice";
                alice++;
            }
            else if (!aliceNeeds && bobNeeds) {
                ans[i] = "Bob";
                bob++;
            }
            else{
                if(alice <= bob){
                    ans[i] = "Alice";
                    alice++;
                }
                else{
                    ans[i] = "Bob";
                    bob++;
                }
            }
        }
        return ans;
    }
};