// Link: https://leetcode.com/problems/minimum-jumps-to-reach-home/?envType=study-plan&id=graph-i

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int minimumJumps(vector<int> &forbidden, int a, int b, int x)
    {
        unordered_map<int, int> um;
        for (auto &pos : forbidden)
        {
            um[pos]++;
        }
        queue<pair<int, pair<int, bool>>> q;

        q.push({0, {0, true}});
        while (!q.empty())
        {
            auto node = q.front();
            int currPos = node.first, ans = node.second.first;
            bool canGoBackwards = node.second.second;
            q.pop();
            if (currPos == x)
                return ans;

            if (um.find(currPos) != um.end())
                continue;
            um[currPos]++;
            int forward = currPos + a, backward = currPos - b;
            if (canGoBackwards and backward >= 0)
            {
                q.push({backward, {ans + 1, false}});
            }
            if (forward <= 2000 + a + b)
            {

                q.push({forward, {ans + 1, true}});
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> forbidden = {14, 4, 18, 1, 15};
    int a = 3, b = 15, x = 9;
    cout << sol.minimumJumps(forbidden, a, b, x) << endl;
    return 0;
}