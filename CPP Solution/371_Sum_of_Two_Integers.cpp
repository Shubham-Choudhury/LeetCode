// Link: https://leetcode.com/problems/sum-of-two-integers/

#include <iostream>
using namespace std;

class Solution
{
public:
    int getSum(int a, int b)
    {
        if (b == 0)
            return a;
        int sum = a ^ b;
        int carry = (unsigned int)(a & b) << 1;
        return getSum(sum, carry);
    }
};

int main()
{
    Solution s;
    cout << s.getSum(1, 2) << endl;
    return 0;
}