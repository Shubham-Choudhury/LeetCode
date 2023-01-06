// Link: https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumSwap(string s1, string s2)
    {
        int xy = 0, yx = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == 'x' && s2[i] == 'y')
                xy++;
            else if (s1[i] == 'y' && s2[i] == 'x')
                yx++;
        }
        if ((xy + yx) % 2 == 1)
            return -1;
        return xy / 2 + yx / 2 + xy % 2 + yx % 2;
    }
};

int main()
{
    Solution s;
    string s1 = "xxyyxyxyxx", s2 = "xyyxyxxxyx";
    cout << s.minimumSwap(s1, s2) << endl;
    return 0;
}
