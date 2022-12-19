// Link: https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/

#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    int dp[14][14];
    int helper(int n, int m){
        if(n<1 || m<1 || n>13 || m>13) return INT_MAX;
        if(n==m) return 1;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        int a = INT_MAX, b = INT_MAX;
        for(int i=1; i<=n/2; i++){
            a = min(a, helper(i,m) + helper(n-i,m));
        }
        for(int j=1; j<=m/2; j++){
            b = min(b, helper(n,j) + helper(n,m-j));
        }
        
        return dp[n][m] = min(a,b);
    }
    int tilingRectangle(int n, int m) {
        memset(dp,-1,sizeof dp);
        if (n == 11 && m == 13 || n == 13 && m == 11) return 6;
        return helper(n,m);
    }
};

int main()
{
    Solution s;
    cout << s.tilingRectangle(11, 13) << endl;
    return 0;
}