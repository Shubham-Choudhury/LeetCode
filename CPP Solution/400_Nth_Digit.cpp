// Link: https://leetcode.com/problems/nth-digit/

#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    int findNthDigit(int n)
    {
        long base = 9, digits = 1, range = 9;
        // calculate the n's length
        while (range < n)
        {
            base *= 10;
            digits += 1;
            range += base * digits;
        }
        // calculate the n's offset
        long offset = n - (range - base * digits);
        // calculate the nth digit belongs to which number
        long number = pow(10, digits - 1) + (offset - 1) / digits;
        // calculate the nth digit is at which digit of the number
        long inner_offset = (offset - 1) % digits;
        // extract the number
        for (int i = 0; i < digits - 1 - inner_offset; i++)
        {
            number /= 10;
        }
        return (int)number % 10;
    }
};

int main()
{
    Solution s;
    cout << s.findNthDigit(1000000000) << endl;
    return 0;
}
