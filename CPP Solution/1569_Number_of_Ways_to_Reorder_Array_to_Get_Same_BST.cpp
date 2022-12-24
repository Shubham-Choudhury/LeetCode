// Link: https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int mod = 1000000007;
    int ans = 1;
    int fac[2001];
    int mod_inverse[2001];
    int mul(int x, int y)
    {
        return ((long long)x * y) % mod;
    }
    int power(int a, int p)
    {
        int ret = 1;
        while (p)
        {
            if (p & 1)
                ret = mul(ret, a);
            a = mul(a, a);
            p /= 2;
        }
        return ret;
    }
    int inv(int x)
    {
        return power(x, mod - 2);
    }
    void factorial()
    {
        fac[0] = 1;
        mod_inverse[0] = 1;

        for (int i = 1; i <= 2000; i++)
        {
            fac[i] = mul(fac[i - 1], i);
            mod_inverse[i] = mul(inv(i), mod_inverse[i - 1]);
        }
    }
    int ncr(int n, int r)
    {
        if (r == 0)
            return 1;
        else if (r == n)
            return 1;
        return mul(fac[n], mul(mod_inverse[r], mod_inverse[n - r]));
    }
    int build(vector<int> &nums, int st, int en)
    {
        if (st > en)
            return 0;
        vector<int> small, big;
        for (int i = st + 1; i <= en; i++)
        {
            if (nums[i] < nums[st])
                small.push_back(nums[i]);
            else
                big.push_back(nums[i]);
        }
        int left = build(small, 0, (int)small.size() - 1);
        int right = build(big, 0, (int)big.size() - 1);
        int num = ncr(left + right, left);
        ans = mul(ans, num);
        return left + right + 1;
    }
    int numOfWays(vector<int> &nums)
    {
        factorial();
        int n = nums.size();
        int tot = build(nums, 0, n - 1);
        return (ans - 1 + mod) % mod;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 1, 3};
    cout << sol.numOfWays(nums) << endl;
    return 0;
}
