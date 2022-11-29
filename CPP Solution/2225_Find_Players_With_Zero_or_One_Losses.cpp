// Link: https://leetcode.com/problems/find-players-with-zero-or-one-losses/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        vector<int> noLoss;
        vector<int> oneLoss;
        map<int, int> mp;
        for (vector<int> match : matches)
        {
            mp[match[1]]++;
        }

        for (vector<int> match : matches)
        {
            int winner = match[0];
            if (mp[winner] == 0)
            {
                noLoss.push_back(winner);
                mp[winner] = -1;
            }
        }

        for (auto it : mp)
        {
            int loseCount = it.second;
            int loser = it.first;
            if (loseCount != -1 && loseCount == 1)
                oneLoss.push_back(loser);
        }

        sort(noLoss.begin(), noLoss.end());

        return {noLoss, oneLoss};
    }
};

int main()
{
    Solution s;
    vector<vector<int>> n = {{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};
    vector<vector<int>> res = s.findWinners(n);
    for (auto &v : res)
    {
        for (auto &i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}