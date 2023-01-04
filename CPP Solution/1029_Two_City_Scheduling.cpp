// Link: https://leetcode.com/problems/two-city-scheduling/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int res = 0, n = costs.size();
        vector<int> diff(n);
        for (int i = 0; i < n; i++)
        {
            res += costs[i][0];
            diff[i] = costs[i][1] - costs[i][0];
        }
        sort(diff.begin(), diff.end());
        for (int i = 0; i < n / 2; i++)
            res += diff[i];
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> costs = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};
    cout << sol.twoCitySchedCost(costs) << endl;
    return 0;
}
