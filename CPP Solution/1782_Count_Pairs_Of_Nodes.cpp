// Link: https://leetcode.com/problems/count-pairs-of-nodes/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countPairs(int n, vector<vector<int>> &edges, vector<int> &queries)
    {
        vector<int> degree(n, 0);
        unordered_map<int, unordered_map<int, int>> gragh;
        for (const vector<int> &edge : edges)
        {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            degree[u]++;
            degree[v]++;
            gragh[u][v]++;
            gragh[v][u]++;
        }
        vector<int> sorted = degree;
        sort(sorted.begin(), sorted.end());

        vector<int> result;
        for (int query : queries)
        {
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                int a = degree[i];
                int left = 0, right = sorted.size() - 1;
                while (left < right)
                {
                    int mid = left + (right - left) / 2;
                    if (a + sorted[mid] <= query)
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid;
                    }
                }
                if (a + sorted[left] > query)
                {
                    int num = sorted.size() - left;
                    int minEdgeNum = sorted[left];
                    for (auto &it : gragh[i])
                    {
                        if (degree[it.first] < minEdgeNum)
                        {
                            // this node is not counted in num
                            continue;
                        }
                        if (a + degree[it.first] - gragh[i][it.first] <= query)
                        {
                            // this adjacent node should not be counted because removing the duplicated count (edges counted twice) it doesn't satisfy the condition
                            num--;
                        }
                    }
                    if (2 * a > query)
                    {
                        // remove counts of node to self
                        num--;
                    }
                    count += num;
                }
            }
            result.push_back(count / 2);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> edges;
    vector<int> queries, ans;

    // Output: [2,1,3]
    edges = {{1, 2}, {2, 4}, {1, 3}, {2, 3}, {2, 1}};
    queries = {2, 3};
    ans = sol.countPairs(4, edges, queries);
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    // Output: [0,0]
    edges = {{1, 2}, {3, 4}, {5, 6}};
    queries = {3, 4};
    ans = sol.countPairs(6, edges, queries);
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
