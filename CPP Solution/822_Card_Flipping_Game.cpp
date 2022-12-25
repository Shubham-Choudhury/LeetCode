// Link: https://leetcode.com/problems/card-flipping-game/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int flipgame(vector<int> &fronts, vector<int> &backs)
    {
        unordered_set<int> s;
        for (int i = 0; i < fronts.size(); i++)
        {
            if (fronts[i] == backs[i])
            {
                s.insert(fronts[i]);
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < fronts.size(); i++)
        {
            if (s.find(fronts[i]) == s.end())
            {
                res = min(res, fronts[i]);
            }
            if (s.find(backs[i]) == s.end())
            {
                res = min(res, backs[i]);
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

int main()
{
    Solution s;
    vector<int> fronts = {1, 2, 4, 4, 7};
    vector<int> backs = {1, 3, 4, 1, 3};
    cout << s.flipgame(fronts, backs) << endl;
    return 0;
}