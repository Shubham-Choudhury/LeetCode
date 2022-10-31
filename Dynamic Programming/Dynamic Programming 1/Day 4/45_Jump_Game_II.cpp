// Link: https://leetcode.com/problems/jump-game-ii/?envType=study-plan&id=dynamic-programming-i

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INT_MAX 1000000000

class Solution {
public:
    int jump(vector<int>& nums) 
    {
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
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution s;
    cout << s.jump(nums) << endl;
    return 0;
}