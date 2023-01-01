// Link: https://leetcode.com/problems/minimum-interval-to-include-each-query/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &_queries)
    {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
             {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0]; });
        priority_queue<pair<int, int>> pq;
        vector<vector<int>> queries(_queries.size());
        for (int i = 0; i < queries.size(); i++)
            queries[i] = {_queries[i], i};
        sort(queries.begin(), queries.end());
        int j = 0;
        map<int, int> cnt;
        vector<int> ans(queries.size());
        for (auto &q : queries)
        {
            int val = q[0], idx = q[1];
            while (j < intervals.size() && intervals[j][0] <= val)
            {
                ++cnt[intervals[j][1] - intervals[j][0]];
                pq.push({-intervals[j][1], j}); // use negative number here so that we can get the smallest right interval.
                j++;
            }
            while (pq.size() && -pq.top().first < val)
            {
                int i = pq.top().second;
                pq.pop();
                int d = intervals[i][1] - intervals[i][0];
                if (--cnt[d] == 0)
                {
                    cnt.erase(d);
                }
            }
            if (cnt.size())
            {
                ans[idx] = cnt.begin()->first + 1;
            }
            else
                ans[idx] = -1;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals;
    vector<int> queries, ans;

    // Output: [3,-1]
    intervals = {{1, 4}, {2, 4}, {3, 6}, {4, 4}}, queries = {2, 3, 4, 5};
    ans = sol.minInterval(intervals, queries);
    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
