// Link: https://leetcode.com/problems/divide-two-integers/

#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        if (divisor == 1)
            return dividend;
        if (dividend == 0)
            return 0;
        unsigned int x = dividend < 0 ? -(unsigned)dividend : (unsigned)dividend;
        unsigned int y = divisor < 0 ? -(unsigned)divisor : (unsigned)divisor;
        int tmp = 1;
        int tmp2 = y;
        while ((x >> 1) >= tmp2)
        {
            tmp <<= 1;
            tmp2 <<= 1;
        }
        int res = 0;
        while (x >= y)
        {
            if (x >= tmp2)
            {
                res += tmp;
                x -= tmp2;
            }
            tmp >>= 1;
            tmp2 >>= 1;
        }
        return ((dividend > 0) ^ (divisor > 0)) ? -res : res;
    }
};

int main()
{
    Solution s;
    cout << s.divide(10, 3) << endl;
    cout << s.divide(7, -3) << endl;
    cout << s.divide(INT_MIN, -1) << endl;
    return 0;
}
