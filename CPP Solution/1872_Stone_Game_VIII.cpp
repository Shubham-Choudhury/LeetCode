// Link: https://leetcode.com/problems/stone-game-viii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int>& a) {
        int n = a.size();
        vector<int> pf(n);
        pf[0] = a[0];
        for(int i = 1; i < n; i++)
            pf[i] = pf[i - 1] + a[i];
        
        int dp[n];
        dp[n - 1] = pf[n - 1];
        for(int i = n - 2; i >= 0; i--)
            dp[i] = max(dp[i + 1], pf[i] - dp[i + 1]);
        
        return dp[1];
    }
};

int main()
{
    Solution s;
    vector<int> a = {-1, 2, -3, 4, -5};
    cout << s.stoneGameVIII(a) << endl;
    return 0;
}
