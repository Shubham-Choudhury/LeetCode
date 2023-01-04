// Link: https://leetcode.com/problems/flower-planting-with-no-adjacent/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>> &paths)
    {
        vector<vector<int>> graph(N);
        for (auto &path : paths)
        {
            graph[path[0] - 1].push_back(path[1] - 1);
            graph[path[1] - 1].push_back(path[0] - 1);
        }
        vector<int> res(N);
        for (int i = 0; i < N; i++)
        {
            vector<bool> used(5);
            for (auto &j : graph[i])
                used[res[j]] = true;
            for (int j = 1; j <= 4; j++)
                if (!used[j])
                    res[i] = j;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    int N = 3;
    vector<vector<int>> paths = {{1, 2}, {2, 3}, {3, 1}};
    vector<int> res = sol.gardenNoAdj(N, paths);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
