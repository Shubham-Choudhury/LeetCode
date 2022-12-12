// Link: https://leetcode.com/problems/concatenated-words/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        vector<string> result;
        for (string word : words) {
            wordSet.erase(word);
            if (canForm(word, wordSet)) {
                result.push_back(word);
            }
            wordSet.insert(word);
        }
        return result;
    }
    
    bool canForm(string word, unordered_set<string>& wordSet) {
        if (wordSet.empty()) return false;
        vector<bool> dp(word.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= word.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (!dp[j]) continue;
                if (wordSet.count(word.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[word.size()];
    }
};

int main() {
    Solution s;
    vector<string> words = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
    vector<string> result = s.findAllConcatenatedWordsInADict(words);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}
