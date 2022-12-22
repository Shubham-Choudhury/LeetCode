// Link: https://leetcode.com/problems/paint-house-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[101][21][101];

    int ff(vector<int> &houses, vector<vector<int>> &cost, int target, int i, int prev_color)
    {

        if (i == houses.size() && target == 0)
            return 0;
        if (i == houses.size() || target == -1)
            return INT_MAX;

        if (prev_color != -1 && target != -1 && dp[i][prev_color][target] != -1)
            return dp[i][prev_color][target];

        int minAns = INT_MAX;
        int idx = i;

        if (houses[idx] == 0)
        {
            for (int j = 0; j < cost[idx].size(); j++)
            {
                int temp;
                if (j + 1 == prev_color)
                    temp = ff(houses, cost, target, idx + 1, prev_color);
                else
                    temp = ff(houses, cost, target - 1, idx + 1, j + 1);

                if (temp != INT_MAX)
                    temp += cost[idx][j];

                minAns = min(minAns, temp);
            }
        }
        else
        {
            int temp;

            if (houses[idx] == prev_color)
                temp = ff(houses, cost, target, idx + 1, prev_color);
            else
                temp = ff(houses, cost, target - 1, idx + 1, houses[idx]);

            minAns = min(minAns, temp);
        }

        if (prev_color != -1 && target != -1)
            return dp[i][prev_color][target] = minAns;

        return minAns;
    }

    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
    {
        memset(dp, -1, sizeof dp);
        int ans = ff(houses, cost, target, 0, -1);
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    vector<int> houses = {0, 0, 0, 0, 0};
    vector<vector<int>> cost = {{1, 10}, {10, 1}, {10, 1}, {1, 10}, {5, 1}};
    int m = 5;
    int n = 2;
    int target = 3;
    Solution sol;
    cout << sol.minCost(houses, cost, m, n, target) << endl;
    return 0;
}
