// Link: https://leetcode.com/problems/frog-jump/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size(),i,j,s;
        
        if(stones[1]!=1 || n<2)return 0;
        if(n==2)return 1;
        
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        dp[1][0]=1;
        
        for(i=2;i<n;i++)
        {
            for(j=1;j<i;j++)
            {
                s=stones[i]-stones[j]-1;
                if(s<n)
                {
                    if(s+1<n && dp[j][s+1])
                        dp[i][s]=1;
                    if(dp[j][s])
                        dp[i][s]=1;
                    if(s-1>=0 && dp[j][s-1])
                        dp[i][s]=1;
                    if(i==n-1 && dp[i][s])
                        return 1;
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
    cout << boolalpha << sol.canCross(stones) << endl;
    return 0;
}