// Link: https://leetcode.com/problems/robot-bounded-in-circle/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        int x = 0, y = 0;
        int dir = 0;
        for (int i = 0; i < instructions.size(); i++)
        {
            if (instructions[i] == 'G')
            {
                if (dir == 0)
                    y++;
                else if (dir == 1)
                    x++;
                else if (dir == 2)
                    y--;
                else
                    x--;
            }
            else if (instructions[i] == 'L')
                dir = (dir + 3) % 4;
            else
                dir = (dir + 1) % 4;
        }
        return (x == 0 && y == 0) || dir != 0;
    }
};

int main()
{
    Solution sol;
    string instructions = "GGLLGG";
    cout << sol.isRobotBounded(instructions) << endl;
    return 0;
}
