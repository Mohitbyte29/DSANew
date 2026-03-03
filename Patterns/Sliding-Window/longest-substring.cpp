//* Best
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// ---------------- Vector method ----------------
int characterReplacement_vector(const string &s, int k) {
    vector<int> freq(26, 0);
    int l = 0, maxFreq = 0, maxLen = 0;

    for (int r = 0; r < s.size(); r++) {
        freq[s[r] - 'A']++;
        maxFreq = max(maxFreq, freq[s[r] - 'A']);

        while ((r - l + 1) - maxFreq > k) {
            freq[s[l] - 'A']--;
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}

// ---------------- Map method ----------------
int characterReplacement_map(const string &s, int k) {
    unordered_map<char, int> freq;
    int l = 0, maxFreq = 0, maxLen = 0;

    for (int r = 0; r < s.size(); r++) {
        freq[s[r]]++;
        

        maxFreq = max(maxFreq, freq[s[r]]);

        while ((r - l + 1) - maxFreq > k) {
            freq[s[l]]--;
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}

int main() {
    // Generate a large test string (100k characters)
    int n = 100000;
    string s;
    s.reserve(n);
    for (int i = 0; i < n; i++) {
        s.push_back('A' + (rand() % 26));
    }
    int k = 5;

    // ------ Benchmark vector ------
    auto start1 = high_resolution_clock::now();
    int ans1 = characterReplacement_vector(s, k);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end1 - start1).count();

    // ------ Benchmark map ------
    auto start2 = high_resolution_clock::now();
    int ans2 = characterReplacement_map(s, k);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(end2 - start2).count();

    // Print results
    cout << "Vector result: " << ans1 
         << " | Time: " << duration1 << " ms\n";

    cout << "Map result: " << ans2 
         << " | Time: " << duration2 << " ms\n";

    return 0;
}