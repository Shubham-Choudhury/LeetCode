// Link: https://leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<vector<int>, int> dp;
    int dfs(vector<int> &cnt, int left)
    {
        auto it = dp.find(cnt);
        if (it != end(dp))
            return it->second;
        int res = 0, bz = cnt.size();
        for (auto j = 1; j < bz; ++j)
        {
            if (--cnt[j] >= 0)
                res = max(res, (left == 0) + dfs(cnt, (bz + left - j) % bz));
            ++cnt[j];
        }
        return dp[cnt] = res;
    }
    int maxHappyGroups(int bz, vector<int> &groups)
    {
        vector<int> cnt(bz);
        int res = 0;
        for (auto group : groups)
        {
            if (group % bz == 0)
                ++res;
            else if (cnt[bz - group % bz])
            {
                --cnt[bz - group % bz];
                ++res;
            }
            else
                ++cnt[group % bz];
        }
        return dfs(cnt, 0) + res;
    }
};

int main()
{
    Solution s;
    vector<int> groups = {1, 2, 3, 4, 5, 6};
    int batchSize = 7;
    cout << s.maxHappyGroups(batchSize, groups) << endl;
    return 0;
}
