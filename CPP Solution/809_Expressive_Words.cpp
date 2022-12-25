// Link: https://leetcode.com/problems/expressive-words/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int ans = 0;
        for (string word : words) {
            if (check(S, word)) {
                ans++;
            }
        }
        return ans;
    }
    
    bool check(string S, string word) {
        int i = 0;
        int j = 0;
        while (i < S.size() && j < word.size()) {
            if (S[i] != word[j]) {
                return false;
            }
            int cnt1 = 0;
            int cnt2 = 0;
            while (i < S.size() && S[i] == S[i + cnt1]) {
                cnt1++;
            }
            while (j < word.size() && word[j] == word[j + cnt2]) {
                cnt2++;
            }
            if (cnt1 < cnt2 || (cnt1 < 3 && cnt1 != cnt2)) {
                return false;
            }
            i += cnt1;
            j += cnt2;
        }
        return i == S.size() && j == word.size();
    }
};

int main() {
    Solution sol;
    string S = "heeellooo";
    vector<string> words = {"hello", "hi", "helo"};
    cout << sol.expressiveWords(S, words) << endl;
    return 0;
}
