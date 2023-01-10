// Link: https://leetcode.com/problems/minimum-number-of-frogs-croaking/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minNumberOfFrogs(string croakOfFrogs)
    {
        int ans = 0;
        int c = 0, r = 0, o = 0, a = 0, k = 0;
        for (int i = 0; i < croakOfFrogs.size(); i++)
        {
            if (croakOfFrogs[i] == 'c')
            {
                c++;
            }
            else if (croakOfFrogs[i] == 'r')
            {
                r++;
            }
            else if (croakOfFrogs[i] == 'o')
            {
                o++;
            }
            else if (croakOfFrogs[i] == 'a')
            {
                a++;
            }
            else if (croakOfFrogs[i] == 'k')
            {
                k++;
            }
            ans = max(ans, c - k);
            if (c < r || r < o || o < a || a < k)
            {
                return -1;
            }
        }
        if (c != r || r != o || o != a || a != k)
        {
            return -1;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string croakOfFrogs = "croakcroak";
    int ans = sol.minNumberOfFrogs(croakOfFrogs);
    cout << ans << endl;
    return 0;
}
