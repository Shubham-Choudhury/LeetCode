// Link: https://leetcode.com/problems/satisfiability-of-equality-equations/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {
        vector<int> parent(26);
        for (int i = 0; i < 26; i++)
            parent[i] = i;
        for (int i = 0; i < equations.size(); i++)
        {
            if (equations[i][1] == '=')
            {
                int x = equations[i][0] - 'a';
                int y = equations[i][3] - 'a';
                int xParent = findParent(parent, x);
                int yParent = findParent(parent, y);
                if (xParent != yParent)
                    parent[xParent] = yParent;
            }
        }
        for (int i = 0; i < equations.size(); i++)
        {
            if (equations[i][1] == '!')
            {
                int x = equations[i][0] - 'a';
                int y = equations[i][3] - 'a';
                int xParent = findParent(parent, x);
                int yParent = findParent(parent, y);
                if (xParent == yParent)
                    return false;
            }
        }
        return true;
    }

    int findParent(vector<int> &parent, int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findParent(parent, parent[x]);
    }
};

int main()
{
    Solution sol;
    vector<string> equations = {"a==b", "b!=a"};
    cout << sol.equationsPossible(equations) << endl;
    return 0;
}
