// Link: https://leetcode.com/problems/broken-calculator/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int brokenCalc(int X, int Y)
    {
        int ans = 0;
        while (Y > X)
        {
            ans++;
            if (Y % 2 == 1)
                Y++;
            else
                Y /= 2;
        }
        return ans + X - Y;
    }
};

int main()
{
    Solution sol;
    cout << sol.brokenCalc(2, 3) << endl;
    cout << sol.brokenCalc(5, 8) << endl;
    cout << sol.brokenCalc(3, 10) << endl;
    cout << sol.brokenCalc(1024, 1) << endl;
    return 0;
}
