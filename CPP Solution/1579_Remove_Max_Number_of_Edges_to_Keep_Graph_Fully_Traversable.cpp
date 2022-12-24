// Link: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findpar(int node, vector<int> &par)
    {

        if (par[node] == node)
            return node;
        return par[node] = findpar(par[node], par);
    }

    void unionbyrank(int x, int y, vector<int> &par, vector<int> &rank)
    {
        int u = findpar(x, par);
        int v = findpar(y, par);

        if (rank[u] > rank[v])
        {
            par[v] = u;
        }
        else if (rank[v] > rank[u])
        {
            par[u] = v;
        }
        else
        {
            par[v] = u;

            rank[u]++;
        }
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {

        vector<int> para(n + 1), parb(n + 1);
        vector<int> ranka(n + 1), rankb(n + 1);

        for (int i = 1; i <= n; i++)
        {
            para[i] = i;
            ranka[i] = 1;
            parb[i] = i;
            rankb[i] = 1;
        }

        int remove = 0;
        for (auto x : edges)
        {
            if (x[0] == 3)
            {
                if (findpar(x[1], para) == findpar(x[2], para) and findpar(x[1], parb) == findpar(x[2], parb))
                {
                    remove += 1;
                }

                unionbyrank(x[1], x[2], para, ranka);
                unionbyrank(x[1], x[2], parb, rankb);
            }
        }

        for (auto x : edges)
        {
            if (x[0] == 2)
            {
                // bob
                if (findpar(x[1], parb) == findpar(x[2], parb))
                {
                    remove += 1;
                }
                unionbyrank(x[1], x[2], parb, rankb);
            }
        }

        for (auto x : edges)
        {
            if (x[0] == 1)
            {
                if (findpar(x[1], para) == findpar(x[2], para))
                {
                    remove += 1;
                }

                unionbyrank(x[1], x[2], para, ranka);
            }
        }

        set<int> alice, bob;

        for (int i = 1; i <= n; i++)
        {
            alice.insert(para[findpar(i, para)]);
            bob.insert(parb[findpar(i, parb)]);
        }
        if (alice.size() > 1 || bob.size() > 1)
            return -1;
        return remove;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges = {{3, 1, 2}, {3, 2, 3}, {1, 1, 3}, {1, 2, 4}, {1, 1, 2}, {2, 3, 4}};
    cout << s.maxNumEdgesToRemove(4, edges) << endl;
    return 0;
}