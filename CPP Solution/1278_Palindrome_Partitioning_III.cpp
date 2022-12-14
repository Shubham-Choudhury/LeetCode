// Link: https://leetcode.com/problems/palindrome-partitioning-iii/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int palindromePartition(string s, int k)
    {

        s = '#' + s;
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n));
        for (int l = 2; l < n; l++)
        {
            for (int j = 1; j <= n - l; j++)
            {
                // cout<<l<<" "<<j<<endl;
                int temp = j + l - 1;
                if (s[j] == s[temp])
                {
                    cost[j][temp] = cost[j + 1][temp - 1];
                }
                else
                {
                    cost[j][temp] = cost[j + 1][temp - 1] + 1;
                }
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX / 2));
        for (int i = 0; i <= k; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                for (int v = j; v <= i; v++)
                {

                    dp[i][j] = min(dp[i][j], dp[v - 1][j - 1] + cost[v][i]);
                }
            }
        }

        return dp[n - 1][k];
    }
};

int main()
{
    Solution s;
    cout << s.palindromePartition("abc", 2) << endl;
    return 0;
}
