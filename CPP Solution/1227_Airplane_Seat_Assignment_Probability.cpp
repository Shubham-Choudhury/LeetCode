// Link: https://leetcode.com/problems/airplane-seat-assignment-probability/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double nthPersonGetsNthSeat(int n)
    {
        if (n == 1)
            return 1;
        return 0.5;
    }
};

int main()
{
    Solution s;
    cout << s.nthPersonGetsNthSeat(1);
    return 0;
}