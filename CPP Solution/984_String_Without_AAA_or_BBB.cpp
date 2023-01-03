// Link: https://leetcode.com/problems/string-without-aaa-or-bbb/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string strWithout3a3b(int A, int B)
    {
        string ans = "";
        while (A > 0 || B > 0)
        {
            bool writeA = false;
            int L = ans.length();
            if (L >= 2 && ans[L - 1] == ans[L - 2])
            {
                if (ans[L - 1] == 'b')
                    writeA = true;
            }
            else
            {
                if (A >= B)
                    writeA = true;
            }
            if (writeA)
            {
                A--;
                ans += 'a';
            }
            else
            {
                B--;
                ans += 'b';
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.strWithout3a3b(1, 2) << endl;
    return 0;
}
