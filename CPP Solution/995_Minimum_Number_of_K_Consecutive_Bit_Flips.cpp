// Link: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

class Solution
{
public:
    int minKBitFlips(vector<int> &A, int K)
    {
        int n = A.size();
        int res = 0;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (!q.empty() && q.front() + K == i)
            {
                q.pop();
            }
            if (q.size() % 2 == A[i])
            {
                if (i + K > n)
                {
                    return -1;
                }
                q.push(i);
                res++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> A = {0, 1, 0};
    int K = 1;
    cout << sol.minKBitFlips(A, K) << endl;
    return 0;
}
