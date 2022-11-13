// Link: https://leetcode.com/problems/longest-palindromic-substring/?envType=study-plan&id=dynamic-programming-i

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLen = 1;
        int start = 0;
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                maxLen = 2;
                start = i;
            }
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    maxLen = len;
                    start = i;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;
    string s = "babad";
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}