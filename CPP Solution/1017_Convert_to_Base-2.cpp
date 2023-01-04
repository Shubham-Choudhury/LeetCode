// Link: https://leetcode.com/problems/convert-to-base-2/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string baseNeg2(int N)
    {
        string res = "";
        while (N)
        {
            res = to_string(N & 1) + res;
            N = -(N >> 1);
        }
        return res == "" ? "0" : res;
    }
};

int main()
{
    Solution sol;
    int N = 2;
    cout << sol.baseNeg2(N) << endl;
    return 0;
}
