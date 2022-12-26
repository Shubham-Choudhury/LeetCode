// Link: https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTrioDegree(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(n + 1, vector<int>(n + 1));
        vector<int> degree(n + 1);
        for (auto &edge : edges)
        {
            graph[edge[0]][edge[1]] = graph[edge[1]][edge[0]] = 1;
            ++degree[edge[0]];
            ++degree[edge[1]];
        }
        int result = INT_MAX;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (graph[i][j])
                {
                    for (int k = j + 1; k <= n; ++k)
                    {
                        if (graph[i][k] && graph[j][k])
                        {
                            result = min(result, degree[i] + degree[j] + degree[k] - 6);
                        }
                    }
                }
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> edges;
    int n, result;

    // Output: 2
    n = 6;
    edges = {{1, 2}, {1, 3}, {3, 2}, {4, 1}, {5, 2}, {3, 6}};
    result = sol.minTrioDegree(n, edges);
    cout << result << endl;

    // Output: 0
    n = 6;
    edges = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
    result = sol.minTrioDegree(n, edges);
    cout << result << endl;

    // Output: -1
    n = 5;
    edges = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5}};
    result = sol.minTrioDegree(n, edges);
    cout << result << endl;

    return 0;
}
