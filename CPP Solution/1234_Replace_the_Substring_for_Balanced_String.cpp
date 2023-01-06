// Link: https://leetcode.com/problems/replace-the-substring-for-balanced-string/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int balancedString(string s)
    {
        int n = s.size();
        int count[4] = {0};
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'Q')
                count[0]++;
            else if (s[i] == 'W')
                count[1]++;
            else if (s[i] == 'E')
                count[2]++;
            else
                count[3]++;
        }
        int k = n / 4;
        if (count[0] == k && count[1] == k && count[2] == k && count[3] == k)
            return 0;
        int res = n;
        int i = 0, j = 0;
        while (j < n)
        {
            if (s[j] == 'Q')
                count[0]--;
            else if (s[j] == 'W')
                count[1]--;
            else if (s[j] == 'E')
                count[2]--;
            else
                count[3]--;
            while (i <= j && count[0] <= k && count[1] <= k && count[2] <= k && count[3] <= k)
            {
                res = min(res, j - i + 1);
                if (s[i] == 'Q')
                    count[0]++;
                else if (s[i] == 'W')
                    count[1]++;
                else if (s[i] == 'E')
                    count[2]++;
                else
                    count[3]++;
                i++;
            }
            j++;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.balancedString("QWER") << endl;
    cout << s.balancedString("QQWE") << endl;
    cout << s.balancedString("QQQW") << endl;
    cout << s.balancedString("QQQQ") << endl;
    return 0;
}
