// Link: https://leetcode.com/problems/factorial-trailing-zeroes/

#include <iostream>
using namespace std;

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int res = 0;
        while (n)
        {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};

int main()
{
    Solution a;
    cout << a.trailingZeroes(3) << endl;
    cout << a.trailingZeroes(5) << endl;
    return 0;
}