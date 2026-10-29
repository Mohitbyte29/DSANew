#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> naiveSearch(const string& text, const string& pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> result;

    for (int i = 0; i + m <= n; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    string text = "ABABCABC";
    string pattern = "ABC";

    vector<int> indices = naiveSearch(text, pattern);

    if (indices.empty()) {
        cout << "Pattern not found\n";
    } else {
        for (int idx : indices) {
            cout << "Pattern found at index " << idx << "\n";
        }
    }
    return 0;
}