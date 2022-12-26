// Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        vector<vector<pair<long, long>>> graph(n, vector<pair<long, long>>());
        queue<tuple<long, long, long>> q;

        for (auto &i : flights)
        {
            int from, to, dist, hops;
            from = i[0], to = i[1], dist = i[2];

            graph[from].emplace_back(to, dist);
            if (from == src)
            {
                dist = hops = 0;
            }
            else
            {
                dist = hops = INT_MAX;
            }
        }

        q.emplace(0, 0, src);
        vector<long> minDist(n, INT_MAX);
        minDist[src] = 0;
        while (not q.empty())
        {
            long currCity, currDist, currHops;
            tie(currDist, currHops, currCity) = q.front(), q.pop();

            if (minDist[currCity] > currDist)
                continue;
            for (auto &n : graph[currCity])
            {

                if (currDist + n.second > minDist[n.first] or currHops + 1 > K + 1)
                    continue;
                q.emplace(currDist + n.second, currHops + 1, n.first);
                minDist[n.first] = min(minDist[n.first], currDist + n.second);
            }
        }

        return (minDist[dst] == INT_MAX) ? -1 : minDist[dst];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> flights;
    int n, src, dst, K, result;

    // Output: 200
    n = 3;
    flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    src = 0;
    dst = 2;
    K = 1;
    result = sol.findCheapestPrice(n, flights, src, dst, K);
    cout << result << endl;

    return 0;
}