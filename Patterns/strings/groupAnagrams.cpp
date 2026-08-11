// * Brute
class Solution {
    bool anagram(string& a, string& b){
        int hash[26] = {0};
        for(char x : a){
            hash[x - 'a']++;
        }
        for(char y : b){
            hash[y - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(hash[i] != 0) return false;
        }
        return true;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        vector<vector<string>> ans;
        int n = arr.size();
        unordered_set<int> used;
        for(int i = 0; i < n; i++){
            if(used.count(i)) continue;
            vector<string> group;
            group.push_back(arr[i]);
            used.insert(i);
            for(int j = i + 1; j < n; j++){
                if(!used.count(j) && anagram(arr[i], arr[j])){
                    group.push_back(arr[j]);
                    used.insert(j);
                }
            }
            ans.push_back(group);
        }
        return ans;
    }
};

// * Optimized
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        int n = arr.size();
        unordered_map<string, vector<string>> mpp;
        for(string s : arr){
            string key = s;
            sort(key.begin(), key.end());
            mpp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& [key, group] : mpp){
            ans.push_back(group);
        }
        return ans;
    }
};