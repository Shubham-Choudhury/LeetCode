// Link: https://leetcode.com/problems/allocate-mailboxes/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[101][101];
    int cost[101][101];

    /* Brute force approach
    int distance(vector<int>& houses, int i, int j, int place) {
        if (dist_dp[i][j][place] != -1) return dist_dp[i][j][place];
        int d = 0;
        for (int idx = i; idx <= j; idx++) {
            d += abs(place - houses[idx]);
        }
        return dist_dp[i][j][place] = d;
    }
    */

    int ff(vector<int> &houses, int k, int i)
    {

        if (i == houses.size() && k == 0)
            return 0;
        if (i == houses.size() || k == 0)
            return INT_MAX;

        int res = INT_MAX;

        if (dp[i][k] != -1)
            return dp[i][k];

        for (int idx = i; idx < houses.size(); idx++)
        {

            /* Median Approach */
            if (cost[i][idx] == -1)
            {
                cost[i][idx] = 0;
                for (int j = i; j <= idx; j++)
                    cost[i][idx] += abs(houses[(i + idx) / 2] - houses[j]);
            }

            /* Brute force approach
            int dist = INT_MAX;
            for (int place = houses[i]; place <= houses[idx]; place++) {
                dist = min(dist, distance(houses, i, idx, place));
            }
            */

            int ans = ff(houses, k - 1, idx + 1);
            if (ans != INT_MAX)
                res = min(res, cost[i][idx] + ans);
        }

        return dp[i][k] = res;
    }

    int minDistance(vector<int> &houses, int k)
    {
        if (k >= houses.size())
            return 0;
        memset(dp, -1, sizeof dp);
        memset(cost, -1, sizeof cost);
        sort(houses.begin(), houses.end());
        return ff(houses, k, 0);
    }
};

int main()
{
    Solution s;
    vector<int> houses = {1, 4, 8, 10, 20};
    int k = 3;
    cout << s.minDistance(houses, k) << endl;
    return 0;
}
