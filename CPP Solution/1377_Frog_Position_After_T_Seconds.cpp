// Link: https://leetcode.com/problems/frog-position-after-t-seconds/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
private:
    double res;
    int target;
    bool dfs(vector<vector<int>> &G, int cur, double prob, int t,
             vector<bool> &visited)
    {
        int remain = 0; // remain child to visite
        for (int child : G[cur])
        {
            if (visited[child] == false)
                ++remain;
        }
        if (t == 0 || remain == 0)
        { // can't walk anymore, no remain steps or no
          // remain unvisited child
            if (cur == target)
            {
                res = prob;
                return true;
            }
            return false;
        }
        prob /= remain; // choose one child
        --t;            // remain step - 1
        for (int child : G[cur])
        {
            if (visited[child])
                continue;
            visited[child] = true;
            if (dfs(G, child, prob, t, visited))
                return true; // this is a tree, only one path to the target node, so
                             // once found, return true
            visited[child] = false;
        }
        return false;
    }

public:
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
    {
        res = 0;
        this->target = target - 1; // index start from zero
        vector<vector<int>> G(n, vector<int>());
        // build the undirected graph (assume that each edge only appear once in
        // edges)
        for (auto &edge : edges)
        {
            // -1: index start from zero
            G[edge[0] - 1].push_back(edge[1] - 1);
            G[edge[1] - 1].push_back(edge[0] - 1);
        }

        vector<bool> visited(n);
        visited[0] = true;
        dfs(G, 0, 1, t, visited); // prob starts as 100%
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges = {{2, 1}, {3, 2}, {4, 1}, {5, 1}, {6, 4}, {7, 1}, {8, 7}};
    int t = 7;
    int target = 7;
    cout << s.frogPosition(8, edges, t, target) << endl;
    return 0;
}
