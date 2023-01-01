// Link: https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumXORSum(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(1 << n, -1));
        return solve(a, b, 0, 0, dp);
    }
    
    int solve(vector<int>& a, vector<int>& b, int i, int mask, vector<vector<int>>& dp){
        if(i == a.size())
            return 0;
        
        if(dp[i][mask] != -1)
            return dp[i][mask];
        
        int ans = INT_MAX;
        for(int j = 0; j < a.size(); j++){
            if((mask & (1 << j)) == 0){
                ans = min(ans, (a[i] ^ b[j]) + solve(a, b, i + 1, mask | (1 << j), dp));
            }
        }
        
        return dp[i][mask] = ans;
    }
};

int main()
{
    Solution s;
    vector<int> a = {1, 2}, b = {2, 3};
    cout << s.minimumXORSum(a, b) << endl;
    return 0;
}