// Link: https://leetcode.com/problems/shortest-path-with-alternating-colors/?envType=study-plan&id=graph-i

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
    vector<vector<int>> redNodes, blueNodes;
    vector<vector<int>> moves;

    void dfs(int i, int move, int flag)
    {
        if (move >= moves[i][flag])
            return;

        moves[i][flag] = min(move, moves[i][flag]);

        if (flag == 0)
            for (auto j : redNodes[i])
                dfs(j, move + 1, 1);
        if (flag == 1)
            for (auto j : blueNodes[i])
                dfs(j, move + 1, 0);
    }

public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        redNodes.resize(n);
        blueNodes.resize(n);
        moves.resize(n, vector<int>(2, 1e3));

        for (auto edge : redEdges)
            redNodes[edge[0]].push_back(edge[1]);
        for (auto edge : blueEdges)
            blueNodes[edge[0]].push_back(edge[1]);

        dfs(0, 0, 0); // Flag : [0] -> red, [1] -> blue
        dfs(0, 0, 1);

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int move = min(moves[i][0], moves[i][1]);

            if (move == 1e3)
                ans[i] = -1;
            else
                ans[i] = move;
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    int m, k;
    cin >> m >> k;
    vector<vector<int>> red_edges(m, vector<int>(2)), blue_edges(k, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> red_edges[i][0] >> red_edges[i][1];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> blue_edges[i][0] >> blue_edges[i][1];
    }
    Solution obj;
    vector<int> ans = obj.shortestAlternatingPaths(n, red_edges, blue_edges);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}