// Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct compar
    {
        bool operator()(const vector<int> &a,
                        const vector<int> &b) const
        {
            return a[1] < b[1];
        }
    };
    int maxValue(vector<vector<int>> &events, int k)
    {
        int n = events.size();
        sort(events.begin(), events.end(), compar()); // sort by end
        vector<int> opt(n);
        for (int i = 0; i != n; ++i)
        {
            vector<int> point = {0, events[i][0]};
            auto it = lower_bound(events.begin(), events.begin() + i + 1, point, compar()); // first one that ends >= when event i starts
            opt[i] = it - events.begin() - 1;                                               // subtract 1 to get the latest good one
        }
        vector<vector<int>> dp(1 + k, vector<int>(n)); // dp[i][j] = max sum using <= i events from events [:j]
        for (int i = 1; i <= k; ++i)
        {
            for (int j = 0; j != n; ++j)
            {
                dp[i][j] = dp[i - 1][j]; // using <= i-1 events is still valid
                if (j)
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]); // don't use this event
                int p = opt[j];                             // latest event ending before this one starts
                dp[i][j] = max(dp[i][j], (p == -1 ? 0 : dp[i - 1][p]) + events[j][2]);
            }
        }
        return dp[k][n - 1];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> events;
    int k, result;

    // Output: 6
    events = {{1, 2, 4}, {3, 4, 3}, {2, 3, 1}}, k = 2;
    result = sol.maxValue(events, k);
    cout << result << endl;

    // Output: 7
    events = {{1, 2, 4}, {3, 4, 3}, {2, 3, 10}}, k = 2;
    result = sol.maxValue(events, k);
    cout << result << endl;

    // Output: 5
    events = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}}, k = 3;
    result = sol.maxValue(events, k);
    cout << result << endl;

    return 0;
}
