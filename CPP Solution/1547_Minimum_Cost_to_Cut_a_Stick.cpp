// Link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int m = cuts.size();
        vector<vector<int>>dp(m, vector<int>(m, 0));
        for (int len = 2; len < m; len++) {
            for (int i = 0; i + len < m; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
                dp[i][j] += cuts[j] - cuts[i];
            }
        }
        return dp[0][m - 1];
    }
};

int main()
{
    Solution sol;
    int n;
    vector<int> cuts;
    int ans;

    // Output: 14
    n = 7;
    cuts = {1,3,4,5};
    ans = sol.minCost(n, cuts);
    cout << ans << endl;

    // Output: 9
    n = 9;
    cuts = {5,6,1,4,2};
    ans = sol.minCost(n, cuts);
    cout << ans << endl;

    return 0;
}
