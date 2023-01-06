// Link: https://leetcode.com/problems/can-make-palindrome-from-substring/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(26, 0));
        for (int i = 1; i <= s.size(); i++)
        {
            dp[i] = dp[i - 1];
            dp[i][s[i - 1] - 'a']++;
        }
        vector<bool> res;
        for (auto q : queries)
        {
            int odd = 0;
            for (int i = 0; i < 26; i++)
            {
                odd += (dp[q[1] + 1][i] - dp[q[0]][i]) % 2;
            }
            res.emplace_back(odd / 2 <= q[2]);
        }
        return res;
    }
};

int main()
{
    Solution s;
    string s1 = "abcda";
    vector<vector<int>> queries = {{3, 3, 0}, {1, 2, 0}, {0, 3, 1}, {0, 3, 2}, {0, 4, 1}};
    vector<bool> res = s.canMakePaliQueries(s1, queries);
    for (auto it : res)
        cout << it << " ";
    return 0;
}

