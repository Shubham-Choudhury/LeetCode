// Link: https://leetcode.com/problems/escape-the-ghosts/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target)
    {
        int dist = abs(target[0]) + abs(target[1]);
        for (auto &ghost : ghosts)
        {
            if (abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]) <= dist)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> ghosts;
    vector<int> target, result;

    // Output: true
    ghosts = {{1, 0}, {0, 3}};
    target = {0, 1};
    // result = sol.escapeGhosts(ghosts, target);
    return 0;
}