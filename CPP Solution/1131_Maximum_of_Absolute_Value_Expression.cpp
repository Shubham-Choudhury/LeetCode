// Link: https://leetcode.com/problems/maximum-of-absolute-value-expression/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxAbsValExpr(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int dp[4][n];
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = arr1[i] + arr2[i] + i;
            dp[1][i] = arr1[i] + arr2[i] - i;
            dp[2][i] = arr1[i] - arr2[i] + i;
            dp[3][i] = arr1[i] - arr2[i] - i;
        }
        int ans = 0;
        for (int i = 0; i < 4; i++)
        {
            int mn = dp[i][0];
            int mx = dp[i][0];
            for (int j = 1; j < n; j++)
            {
                mn = min(mn, dp[i][j]);
                mx = max(mx, dp[i][j]);
                ans = max(ans, mx - mn);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2 = {-1, 4, 5, 6};
    cout << s.maxAbsValExpr(arr1, arr2) << endl;
    return 0;
}
