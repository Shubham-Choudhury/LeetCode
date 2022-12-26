// Link: https://leetcode.com/problems/tree-of-coprimes/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges)
    {
        vector<vector<int>> coprimes(51);
        for (int i = 1; i <= 50; ++i)
        {
            vector<int> v;
            for (int j = 1; j <= 50; ++j)
            {
                if (gcd(i, j) == 1)
                    v.push_back(j);
            }
            coprimes[i] = v;
        }

        int n = nums.size();
        vector<list<int>> G(n);
        for (vector<int> &e : edges)
        {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }

        vector<int> res(n);
        vector<bool> vis(n, false);

        function<void(int, vector<int> &)> dfs = [&](int u, vector<int> &c)
        {
            res[u] = c[nums[u]];
            vis[u] = true;

            for (int v : G[u])
            {
                if (!vis[v])
                {
                    vector<int> nc = c;
                    for (int x : coprimes[nums[u]])
                        nc[x] = u;
                    dfs(v, nc);
                }
            }
        };
        vector<int> c(51, -1);
        dfs(0, c);
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    vector<vector<int>> edges;
    vector<int> result;

    // Output: [-1,0,1,1,1,0,0,0]
    nums = {5, 6, 10, 2, 3, 6, 15};
    edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
    result = sol.getCoprimes(nums, edges);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }

    return 0;
}
