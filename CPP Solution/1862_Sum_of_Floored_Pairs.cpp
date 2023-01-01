// Link: https://leetcode.com/problems/sum-of-floored-pairs/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
class Solution
{
public:
    int sumOfFlooredPairs(vector<int> &a)
    {
        ll i, n = a.size(), j, mx = -1;

        for (i = 0; i < n; i++)
            if (mx < a[i])
                mx = a[i];

        bool vis[mx + 10];
        memset(vis, 0, sizeof(vis));

        ll mxx = mx << 2;

        ll f[10 + mxx], pf[10 + mxx];
        memset(f, 0, sizeof(f));

        for (i = 0; i < n; i++)
            f[a[i]]++;

        pf[0] = f[0];
        for (i = 1; i < 10 + mxx; i++)
            pf[i] = pf[i - 1] + f[i];

        ll ans = 0;

        for (j = 0; j < n; j++)
        {
            i = a[j];
            if (vis[i])
                continue;

            vis[i] = 1;
            ll left = i - 1, right = 2 * i - 1, mf = 1;
            ll cntl = pf[left], cntr = pf[right];

            while (left <= mx)
            {
                ans = (ans + (mf * (f[i] * (cntr - cntl)) % mod) % mod) % mod;

                left += i;
                right += i;

                cntl = pf[left];
                cntr = pf[right];

                mf++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution a;
    vector<int> input = {2, 5, 9};
    cout << a.sumOfFlooredPairs(input) << endl;
    return 0;
}
