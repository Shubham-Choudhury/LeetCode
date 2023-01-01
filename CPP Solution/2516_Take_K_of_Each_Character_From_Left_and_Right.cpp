// Link: https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int takeCharacters(string s, int k)
    {
        int ca = 0, cb = 0, cc = 0;
        int n = s.size();
        int ans = n;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
                ca++;
            if (s[i] == 'b')
                cb++;
            if (s[i] == 'c')
                cc++;
        }
        if (ca < k || cb < k || cc < k)
            return -1;
        int i = n - 1, j = n - 1;
        while (i >= 0)
        {
            if (s[i] == 'a')
                ca--;
            if (s[i] == 'b')
                cb--;
            if (s[i] == 'c')
                cc--;
            while (ca < k || cb < k || cc < k)
            {
                if (s[j] == 'a')
                    ca++;
                if (s[j] == 'b')
                    cb++;
                if (s[j] == 'c')
                    cc++;
                j--;
            }
            ans = min(ans, i + n - 1 - j);
            i--;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string s1 = "abcabc";
    cout << s.takeCharacters(s1, 2) << endl;
    return 0;
}
