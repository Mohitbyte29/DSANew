#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[2];

    Node() {
        links[0] = links[1] = NULL;
    }

    bool containsKey(int bit) {
        return links[bit] != NULL;
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;

        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if(node->containsKey(1 - bit)) {
                maxNum |= (1 << i);   // set ith bit
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;

        for(int num : nums) {
            trie.insert(num);
        }

        int maxi = 0;

        for(int num : nums) {
            maxi = max(maxi, trie.getMax(num));
        }

        return maxi;
    }
};

int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    Solution sol;

    cout << sol.findMaximumXOR(nums) << endl;
    return 0;
}