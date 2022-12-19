// Link: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/

#include <iostream>
#include <vector>   
using namespace std;

class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mod = 1e9+7;
        int n = min(steps/2+1,arrLen);
        vector<vector<int>> dp(steps+1,vector<int>(n,0));
        dp[0][0] = 1;
        for(int i=1; i<=steps; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = dp[i-1][j];
                if(j-1>=0) dp[i][j] = (dp[i][j] + dp[i-1][j-1])%mod;
                if(j+1<n) dp[i][j] = (dp[i][j] + dp[i-1][j+1])%mod;
            }
        }
        return dp[steps][0];
    }
};

int main()
{
    Solution s;
    cout << s.numWays(3,2) << endl;
    return 0;
}
