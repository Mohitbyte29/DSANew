#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    bool flag = false;

    Node() {
        for(int i = 0; i < 26; i++) links[i] = NULL;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool checkPrefixes(string word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch))
                return false;

            node = node->get(ch);

            if(!node->isEnd())
                return false;
        }
        return true;
    }
};

class Solution {
public:
    string longestValidWord(vector<string>& words) {
        Trie trie;

        for(auto &word : words) {
            trie.insert(word);
        }

        string ans = "";

        for(auto &word : words) {
            if(trie.checkPrefixes(word)) {
                if(word.length() > ans.length()) {
                    ans = word;
                }
                else if(word.length() == ans.length() && word < ans) {
                    ans = word;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<string> words = {"a", "ap", "app", "appl", "apple", "apply"};

    cout << sol.longestValidWord(words) << endl;

    return 0;
}