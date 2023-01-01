// Link: https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            if (i < n - 1 && s[i] == s[i + 1]) {
                dp[i][i + 1] = 2;
            }
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < word1.size(); i++) {
            for (int j = word1.size(); j < n; j++) {
                if (s[i] == s[j]) {
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string word1, word2;
    int ans;

    // Output: 5
    word1 = "cacb", word2 = "cbba";
    ans = sol.longestPalindrome(word1, word2);
    cout << ans << endl;
    return 0;
}