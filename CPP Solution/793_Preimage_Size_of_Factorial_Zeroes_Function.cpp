// Link: https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/

#include <iostream>
using namespace std;

class Solution
{
public:
    int preimageSizeFZF(int K)
    {
        long long lo = 0, hi = 5LL * (K + 1);
        while (lo < hi)
        {
            long long mi = lo + (hi - lo) / 2;
            if (trailingZeroes(mi) < K)
                lo = mi + 1;
            else
                hi = mi;
        }
        return trailingZeroes(lo) == K ? 5 : 0;
    }

    int trailingZeroes(long long n)
    {
        int res = 0;
        while (n > 0)
        {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};

int main()
{
    int K = 0;
    Solution obj;
    cout << obj.preimageSizeFZF(K) << endl;
    return 0;
}
