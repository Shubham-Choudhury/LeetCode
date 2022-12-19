// Link: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys, vector<vector<int>> &containedBoxes, vector<int> &initialBoxes)
    {
        int n = status.size();
        vector<bool> visited(n, false);
        queue<int> q;
        for (int i = 0; i < initialBoxes.size(); i++)
        {
            q.push(initialBoxes[i]);
        }
        int ans = 0;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            if (visited[x])
                continue;
            visited[x] = true;
            if (status[x] == 1)
            {
                ans += candies[x];
                for (int i = 0; i < keys[x].size(); i++)
                {
                    status[keys[x][i]] = 1;
                }
                for (int i = 0; i < containedBoxes[x].size(); i++)
                {
                    q.push(containedBoxes[x][i]);
                }
            }
            else
            {
                q.push(x);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> status = {1, 0, 1, 0};
    vector<int> candies = {7, 5, 4, 100};
    vector<vector<int>> keys = {{}, {}, {1}, {}};
    vector<vector<int>> containedBoxes = {{1, 2}, {3}, {}, {}};
    vector<int> initialBoxes = {0};
    cout << s.maxCandies(status, candies, keys, containedBoxes, initialBoxes) << endl;
    return 0;
}
