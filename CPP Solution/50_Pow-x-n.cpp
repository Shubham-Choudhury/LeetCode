// Link: https://leetcode.com/problems/powx-n/

#include <iostream>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n == -1)
            return 1 / x;
        double tmp = myPow(x, n / 2);
        return tmp * tmp * myPow(x, n % 2);
    }
};

int main()
{
    Solution s;
    cout << s.myPow(2.00000, 10) << endl;
    cout << s.myPow(2.10000, 3) << endl;
    cout << s.myPow(2.00000, -2) << endl;
    return 0;
}