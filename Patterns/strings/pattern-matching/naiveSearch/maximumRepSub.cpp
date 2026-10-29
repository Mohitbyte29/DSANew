class Solution {
public:
    int maxRepeating(string sequence, string word) {
        if(sequence.find(word) == string::npos) return 0;
        string res = word;
        int cnt = 0;
        while(sequence.find(res) != string::npos){
            res += word;
            cnt++;
        }
        return cnt;
    }
};