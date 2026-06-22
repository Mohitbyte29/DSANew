class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<vector<string>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        q.push({beginWord});
        vector<vector<string>> ans;
        vector<string> usedOnLevel;
        int level = 0;
        usedOnLevel.push_back(beginWord);
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            if(vec.size() > level){
                level++;
                for(auto it:usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear();
            }
            string word = vec.back();
            if(word == endWord){
                if(ans.empty()){
                    ans.push_back(vec);
                }
                else if(ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i = 0; i<word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.count(word) > 0){
                        vec.push_back(word);
                        usedOnLevel.push_back(word);
                        q.push({vec});
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};