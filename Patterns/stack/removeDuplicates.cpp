#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string str = "";
        int n = s.size();
        unordered_map<char, int> mp;
        unordered_set<char> seen;
        for(char ch : s){
            mp[ch]++;
        }
        for(char ch : s){
            mp[ch]--;
            if(seen.count(ch)) continue;

            while(!str.empty() && str.back() > ch && mp[str.back()] > 0){
                seen.erase(str.back());
                str.pop_back();
            }
            str += ch;
            seen.insert(ch);
        }
        return str;
    }
};