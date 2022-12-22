// Link: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size(), n = pizza[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + (pizza[i][j] == 'A');
            }
        }
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1)));
        return dfs(sum, dp, 0, 0, k);
    }
    
    int dfs(vector<vector<int>>& sum, vector<vector<vector<int>>>& dp, int i, int j, int k) {
        if (sum.back().back() - sum[i].back() - sum.back()[j] + sum[i][j] == 0) {
            return 0;
        }
        if (k == 1) {
            return 1;
        }
        if (dp[i][j][k] > 0) {
            return dp[i][j][k];
        }
        int m = sum.size() - 1, n = sum[0].size() - 1;
        int res = 0;
        for (int x = i + 1; x < m; ++x) {
            if (sum[x].back() - sum[x][j] - sum[i].back() + sum[i][j] > 0 && sum.back().back() - sum[x].back() - sum.back()[j] + sum[x][j] > 0) {
                res = (res + dfs(sum, dp, x, j, k - 1)) % 1000000007;
            }
        }
        for (int y = j + 1; y < n; ++y) {
            if (sum.back()[y] - sum[i][y] - sum.back()[j] + sum[i][j] > 0 && sum.back().back() - sum.back()[y] - sum[m][j] + sum[m][y] > 0) {
                res = (res + dfs(sum, dp, i, y, k - 1)) % 1000000007;
            }
        }
        dp[i][j][k] = res;
        return res;
    }
};

int main(void)
{
    Solution sol;
    vector<string> pizza = {"A..", "AAA", "..."};
    int k = 3;
    int res = sol.ways(pizza, k);
    cout << res << endl;
    return 0;
}
