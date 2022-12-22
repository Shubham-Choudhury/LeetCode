// Link: https://leetcode.com/problems/max-dot-product-of-two-subsequences/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxDotProduct(vector<int> &s, vector<int> &t)
    {
        int M = s.size(), N = t.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, INT_MIN));
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                dp[i + 1][j + 1] = max({max(0, dp[i][j]) + s[i] * t[j], dp[i + 1][j], dp[i][j + 1]});
            }
        }
        return dp[M][N];
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums1 = {2, 1, -2, 5};
    vector<int> nums2 = {3, 0, -6};
    int res = sol.maxDotProduct(nums1, nums2);
    cout << res << endl;
    return 0;
}
