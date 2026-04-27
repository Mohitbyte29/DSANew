#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    int cntEndsWith = 0;
    int cntPrefix = 0;

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

    void increaseEnd() {
        cntEndsWith++;
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void reducePrefix() {
        cntPrefix--;
    }

    void reduceEnd() {
        cntEndsWith--;
    }

    int getEnd() {
        return cntEndsWith;
    }

    int getPrefix() {
        return cntPrefix;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // Insert word
    void insert(string word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    // Count exact word
    int countWordsEqualTo(string word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) return 0;
            node = node->get(ch);
        }
        return node->getEnd();
    }

    // Count words with prefix
    int countWordsStartingWith(string prefix) {
        Node* node = root;
        for(char ch : prefix) {
            if(!node->containsKey(ch)) return 0;
            node = node->get(ch);
        }
        return node->getPrefix();
    }

    // Erase word
    void erase(string word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) return;
            node = node->get(ch);
            node->reducePrefix();
        }
        node->reduceEnd();
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("apple");
    trie.insert("app");

    cout << trie.countWordsEqualTo("apple") << endl;   // 2
    cout << trie.countWordsStartingWith("app") << endl; // 3

    trie.erase("apple");

    cout << trie.countWordsEqualTo("apple") << endl;   // 1
    cout << trie.countWordsStartingWith("app") << endl; // 2

    return 0;
}