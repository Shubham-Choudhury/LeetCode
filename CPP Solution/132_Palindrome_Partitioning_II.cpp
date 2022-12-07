// Link: https://leetcode.com/problems/palindrome-partitioning-ii/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        vector<int> dp(n, 0);
        
        for (int i = 0; i < n; i++) {
            dp[i] = i;
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j < 2 || isPalindrome[j + 1][i - 1])) {
                    isPalindrome[j][i] = true;
                    if (j == 0) {
                        dp[i] = 0;
                    } else {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }
        
        return dp[n - 1];
    }
};

int main() {
    Solution sol;
    string s;
    int result;
    
    s = "aab";
    result = sol.minCut(s);
    cout << result << endl;
    
    s = "a";
    result = sol.minCut(s);
    cout << result << endl;
    
    s = "ab";
    result = sol.minCut(s);
    cout << result << endl;
    
    s = "aaabaa";
    result = sol.minCut(s);
    cout << result << endl;
    
    s = "ababababababababababababcbabababababababababababa";
    result = sol.minCut(s);
    cout << result << endl;
    
    return 0;
}