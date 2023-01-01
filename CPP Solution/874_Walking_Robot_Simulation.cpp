// Link: https://leetcode.com/problems/walking-robot-simulation/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        int x = 0, y = 0;
        int dx = 0, dy = 1;
        int ans = 0;
        set<pair<int, int>> obstacleSet;
        for (auto obstacle : obstacles)
        {
            obstacleSet.insert(make_pair(obstacle[0], obstacle[1]));
        }
        for (auto command : commands)
        {
            if (command == -2)
            {
                int temp = dx;
                dx = -dy;
                dy = temp;
            }
            else if (command == -1)
            {
                int temp = dx;
                dx = dy;
                dy = -temp;
            }
            else
            {
                for (int i = 0; i < command; i++)
                {
                    if (obstacleSet.count(make_pair(x + dx, y + dy)) == 0)
                    {
                        x += dx;
                        y += dy;
                        ans = max(ans, x * x + y * y);
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> commands = {4, -1, 3};
    vector<vector<int>> obstacles = {};
    cout << s.robotSim(commands, obstacles) << endl;
    return 0;
}
