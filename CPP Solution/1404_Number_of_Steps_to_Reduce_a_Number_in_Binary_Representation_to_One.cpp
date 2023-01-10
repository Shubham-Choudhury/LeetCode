// Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSteps(string &s)
    {
        int res = 0, carry = 0;
        for (auto i = s.size() - 1; i > 0; --i)
        {
            ++res;
            if (s[i] - '0' + carry == 1)
            {
                carry = 1;
                ++res;
            }
        }
        return res + carry;
    }
};

int main()
{
    Solution sol;
    string s = "1101";
    int ans = sol.numSteps(s);
    cout << ans << endl;
    return 0;
}
