// Link: https://leetcode.com/problems/smallest-integer-divisible-by-k/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestRepunitDivByK(int K)
    {
        if (K % 2 == 0 || K % 5 == 0)
            return -1;
        int remainder = 0;
        for (int N = 1; N <= K; N++)
        {
            remainder = (remainder * 10 + 1) % K;
            if (remainder == 0)
                return N;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    int K = 1;
    cout << sol.smallestRepunitDivByK(K) << endl;
    return 0;
}
