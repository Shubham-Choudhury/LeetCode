// Link: https://leetcode.com/problems/minimum-space-wasted-from-packaging/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minWastedSpace(vector<int> &packages, vector<vector<int>> &boxes)
    {
        sort(packages.begin(), packages.end());
        int n = packages.size();
        vector<long long> prefix(packages.size());
        prefix[0] = packages[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + (long long)packages[i];
        }
        long long ans = 1e18;
        for (auto &b : boxes)
        {
            sort(b.begin(), b.end());
            long long sum = 0;
            int i = 0, j = 0;
            int m = b.size();
            while (i < n && j < m)
            {
                int idx = upper_bound(packages.begin() + i, packages.end(), b[j]) - packages.begin();
                if (idx == i)
                {
                    j++;
                    continue;
                }
                --idx;
                sum += (long long)b[j] * (long long)(idx - i + 1) - (long long)(prefix[idx] - (i > 0 ? prefix[i - 1] : 0));
                i = idx + 1;
                j++;
            }
            if (i == n)
            {
                ans = min(sum, ans);
            }
        }
        return ans == 1e18 ? -1 : ans % 1000000007;
    }
};

int main()
{
    Solution s;
    vector<int> packages = {2, 3, 5};
    vector<vector<int>> boxes = {{4, 8}, {2, 8}};
    cout << s.minWastedSpace(packages, boxes) << endl;
    return 0;
}
