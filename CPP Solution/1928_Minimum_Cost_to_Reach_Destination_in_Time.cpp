// Link: https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/

#include <bits/stdc++.h>
using namespace std;


class Solution
{
private:
    class City
    {
    public:
        int i;
        int cost;
        int time;
        City(int i, int cost, int time) : i(i), cost(cost), time(time) {}
    };
    struct cityComparator
    {
        bool operator()(City const &c1, City const &c2)
        {
            return c1.cost > c2.cost;
        }
    };

public:
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees)
    {
        int n = passingFees.size();
        priority_queue<City, vector<City>, cityComparator> cq;
        cq.push(City(0, passingFees[0], 0));
        vector<vector<pair<int, int>>> adj(n);
        for (vector<int> &edge : edges)
        {
            adj[edge[0]].push_back(make_pair(edge[1], edge[2]));
            adj[edge[1]].push_back(make_pair(edge[0], edge[2]));
        }
        vector<int> seen(n, maxTime + 1);
        while (!cq.empty())
        {
            City c = cq.top();
            cq.pop();
            if (seen[c.i] <= c.time)
                continue;
            seen[c.i] = c.time;
            if (c.i == n - 1 && c.time <= maxTime)
                return c.cost;
            for (int i = 0; i < adj[c.i].size(); i++)
            {
                int ni = adj[c.i][i].first;
                int nt = adj[c.i][i].second;
                if (c.time + nt < seen[ni])
                {
                    cq.push(City(ni, c.cost + passingFees[ni], c.time + nt));
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {1, 3, 7}, {2, 3, 1}, {3, 4, 1}, {3, 5, 1}, {4, 6, 1}, {5, 6, 1}};
    vector<int> passingFees = {0, 3, 4, 5, 6, 7, 8, 9};
    cout << s.minCost(27, edges, passingFees) << endl;
    return 0;
}
