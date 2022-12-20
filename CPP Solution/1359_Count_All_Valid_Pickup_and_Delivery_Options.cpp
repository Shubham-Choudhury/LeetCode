// Link: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countOrders(int n) {
        vector<vector<long> > dp(n+1,vector<long>(n+1,-1));
        return solve(n,dp,0,0);
    }
    long solve(int n, vector<vector<long> >& dp, int p, int d){
        if(p==n && d==n) return 1;
        if(dp[p][d]!=-1) return dp[p][d];
        dp[p][d]=0;
        //we can pick any order independently
		//any one of the (n-p) orders can be picked at this state 
        if(p<n){
            dp[p][d]+=(n-p)*(solve(n,dp,p+1,d));
            dp[p][d]%=1000000007;
        }
        // we can deliver only if number of pickups is greater then number of deliveries
		// any one of the (p-d) orders can be can be delivered at this state 
        if(p>d && d<n){
            dp[p][d]+=(p-d)*(solve(n,dp,p,d+1));
            dp[p][d]%=1000000007;
        }
        return dp[p][d];
    }
};

int main() {
    Solution sol;
    int n;
    
    n = 1;
    cout << sol.countOrders(n) << endl;
    
    n = 2;
    cout << sol.countOrders(n) << endl;
    
    n = 3;
    cout << sol.countOrders(n) << endl;
    
    return 0;
}
