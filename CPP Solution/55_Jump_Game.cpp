// Link: https://leetcode.com/problems/jump-game/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int>dp;
    bool canJump(vector<int>& nums) 
    {
        dp.resize(nums.size(),-1);
        int idx=0;
        return fun(nums,idx);        
    }
    bool fun(vector<int>&nums,int idx)
    {
        if(idx >=nums.size())
        return 0;

        if(idx == nums.size()-1)
        return 1;

        if(dp[idx]!=-1)
        {
            return dp[idx];
        }

        int k = nums[idx];

        for(int i=1;i<=k;i++)
        {
            if(fun(nums,idx+i)==true)
            {
                return dp[idx]=1;
            }
        }
        return dp[idx]=0;
    }
};

int main()
{
    vector<int>nums={2,3,1,1,4};
    Solution s;
    cout<<s.canJump(nums)<<endl;
    return 0;
}