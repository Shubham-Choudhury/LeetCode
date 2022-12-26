// Link: https://leetcode.com/problems/palindrome-partitioning-iv/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkPartitioning(string s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
            if (i < n - 1 && s[i] == s[i + 1])
                dp[i][i + 1] = true;
        }
        for (int len = 3; len <= n; len++)
        {
            for (int i = 0; i < n - len + 1; i++)
            {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1])
                    dp[i][j] = true;
            }
        }
        for (int i = 0; i < n - 2; i++)
        {
            if (dp[0][i])
            {
                for (int j = i + 1; j < n - 1; j++)
                {
                    if (dp[i + 1][j] && dp[j + 1][n - 1])
                        return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    string s;
    bool result;

    // Output: true
    s = "abcbdd";
    result = sol.checkPartitioning(s);
    cout << result << endl;

    // Output: false
    s = "bcbddxy";
    result = sol.checkPartitioning(s);
    cout << result << endl;

    return 0;
}
