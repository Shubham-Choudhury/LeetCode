// Link: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        int res = 0;
        while (n)
        {
            res ^= n;
            n >>= 1;
        }
        return res;
    }
};

int main()
{
    Solution a;
    cout << a.minimumOneBitOperations(0) << endl;
    cout << a.minimumOneBitOperations(3) << endl;
    cout << a.minimumOneBitOperations(6) << endl;
    cout << a.minimumOneBitOperations(9) << endl;
    cout << a.minimumOneBitOperations(333) << endl;
    return 0;
}
