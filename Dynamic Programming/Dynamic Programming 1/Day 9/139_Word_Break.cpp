// Link: https://leetcode.com/problems/word-break/?envType=study-plan&id=dynamic-programming-i

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    cout << s.wordBreak(s1, wordDict1) << endl;
    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};
    cout << s.wordBreak(s2, wordDict2) << endl;
    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << s.wordBreak(s3, wordDict3) << endl;
    return 0;
}