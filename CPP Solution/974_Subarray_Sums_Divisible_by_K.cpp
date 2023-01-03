// Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &A, int K)
    {
        unordered_map<int, int> m;
        m[0] = 1;
        int res = 0, sum = 0;
        for (auto &i : A)
        {
            sum += i;
            int mod = (sum % K + K) % K;
            res += m[mod];
            ++m[mod];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> A = {4, 5, 0, -2, -3, 1};
    int K = 5;
    cout << sol.subarraysDivByK(A, K) << endl;
    return 0;
}
