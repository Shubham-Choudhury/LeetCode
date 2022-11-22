// Link: https://leetcode.com/problems/jump-game-ii/?envType=study-plan&id=algorithm-ii

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,INT_MAX);
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            int k = nums[i];
            for(int j=1;j<=k;j++)
            {
                if(i+j<n)
                {
                    dp[i+j]=min(dp[i+j],dp[i]+1);
                }
            }
        }
        return dp[n-1];
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,3,1,1,4};
    cout << s.jump(nums) << endl;
    return 0;
}