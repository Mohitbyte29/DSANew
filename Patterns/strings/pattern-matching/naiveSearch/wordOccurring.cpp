class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        int n = searchWord.size();
        vector<string> res;
        string t;
        while(ss >> t) res.push_back(t);
        for(int i = 0; i < res.size(); i++){
            if(searchWord == res[i].substr(0, n)){
                return i + 1;
            }
        }
        return -1;
    }
};