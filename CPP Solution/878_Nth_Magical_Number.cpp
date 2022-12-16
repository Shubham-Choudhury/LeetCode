// Link: https://leetcode.com/problems/nth-magical-number/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int nthMagicalNumber(int N, int A, int B)
    {
        long long lcm = (long long)A * B / __gcd(A, B);
        long long lo = 0;
        long long hi = (long long)N * min(A, B);
        while (lo < hi)
        {
            long long mid = lo + (hi - lo) / 2;
            long long cnt = mid / A + mid / B - mid / lcm;
            if (cnt < N)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        return lo % 1000000007;
    }
};

int main()
{
    Solution sol;
    int N;
    int A;
    int B;

    // Output: 2
    N = 1, A = 2, B = 3;
    cout << sol.nthMagicalNumber(N, A, B) << endl;

    // Output: 6
    N = 4, A = 2, B = 3;
    cout << sol.nthMagicalNumber(N, A, B) << endl;

    return 0;
}