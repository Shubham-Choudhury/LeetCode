// Link: https://leetcode.com/problems/dice-roll-simulation/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dieSimulator(int n, vector<int>& rmax) {
        int m = 1000000007;
        
        int maxe = 0;
        for(int x: rmax) if(x> maxe) maxe = x;
        
        vector<vector<int>> dp(6,vector<int>(maxe,0));
        //dp[j][k] stores num ways if end with digit j and its repeated k times
        
        for(int j=0; j<6; j++) dp[j][0] = 1;
       
        
        for(int i=1; i<n; i++){
            vector<vector<int>> dp2(6,vector<int>(maxe,0));
            
            for(int j=0; j<6; j++){
                for(int k=0; k<maxe; k++){
                    if(k==0){
                        //Last digit can't be equal to j
                        for(int l=0; l<6; l++) if(l!=j) 
                        for(int k1=0; k1<rmax[l]; k1++) {
                            dp2[j][0] += dp[l][k1];
                            dp2[j][0] %= m;
                        }
                    }
                    else if(k < rmax[j]) dp2[j][k] = dp[j][k-1];
                }
            }
            dp = dp2;
            
        }
        
        int ans = 0;
        for(int j=0; j<6; j++) for(int k=0; k<maxe; k++) if(k<rmax[j]){
            ans+= dp[j][k];
            ans%=m;
        }
        
        return ans;
        
    }
};

int main()
{
    Solution s;
    vector<int> rollMax = {1, 1, 2, 2, 2, 3};
    cout << s.dieSimulator(2, rollMax) << endl;
    return 0;
}
