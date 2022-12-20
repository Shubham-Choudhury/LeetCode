// Link: https://leetcode.com/problems/dota2-senate/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        int n = senate.size();
        int r = 0, d = 0;
        for (int i = 0; i < n; ++i)
        {
            if (senate[i] == 'R')
            {
                r++;
            }
            else
            {
                d++;
            }
        }
        int r_ban = 0, d_ban = 0;
        while (r > 0 && d > 0)
        {
            for (int i = 0; i < n; ++i)
            {
                if (senate[i] == 'R')
                {
                    if (d_ban > 0)
                    {
                        senate[i] = 'X';
                        d_ban--;
                        r--;
                    }
                    else
                    {
                        r_ban++;
                    }
                }
                else if (senate[i] == 'D')
                {
                    if (r_ban > 0)
                    {
                        senate[i] = 'X';
                        r_ban--;
                        d--;
                    }
                    else
                    {
                        d_ban++;
                    }
                }
            }
        }
        return r > 0 ? "Radiant" : "Dire";
    }
};

int main()
{
    Solution s;
    string str = "RDD";
    cout << s.predictPartyVictory(str) << endl;
    return 0;
}
