// Link: https://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSkips(vector<int> &A, int s, int target)
    {
        int n = A.size();
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = n; j >= 0; --j)
            {
                dp[j] += A[i];
                if (i < n - 1)
                    dp[j] = (dp[j] + s - 1) / s * s; // take a rest
                if (j > 0)
                    dp[j] = min(dp[j], dp[j - 1] + A[i]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (dp[i] <= (long)s * target)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> a = {1, 3, 2};
    cout << s.minSkips(a, 4, 2) << endl;
    return 0;
}
