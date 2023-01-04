// Link: https://leetcode.com/problems/clumsy-factorial/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int clumsy(int N)
    {
        if (N == 1)
            return 1;
        if (N == 2)
            return 2;
        if (N == 3)
            return 6;
        if (N == 4)
            return 7;
        if (N % 4 == 1)
            return N + 2;
        if (N % 4 == 2)
            return N + 2;
        if (N % 4 == 3)
            return N - 1;
        return N + 1;
    }
};

int main()
{
    Solution sol;
    cout << sol.clumsy(4) << endl;
    cout << sol.clumsy(10) << endl;
    return 0;
}
