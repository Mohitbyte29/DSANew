#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];

    Node() {
        for(int i = 0; i < 26; i++) links[i] = NULL;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

int countDistinctSubstrings(string s) {
    Node* root = new Node();
    int count = 0;

    for(int i = 0; i < s.length(); i++) {
        Node* node = root;

        for(int j = i; j < s.length(); j++) {
            if(!node->containsKey(s[j])) {
                node->put(s[j], new Node());
                count++;  // new substring found
            }
            node = node->get(s[j]);
        }
    }

    return count + 1; // +1 for empty substring
}

int main() {
    string s = "ababa";
    cout << countDistinctSubstrings(s) << endl;
    return 0;
}