// Link: https://leetcode.com/problems/largest-divisible-subset/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>dp(nums.size(), 1);
        vector<int>parent(nums.size(), -1);
        int max_index = 0;
        for(int i = 1; i < nums.size(); i++)
            for(int j = i - 1; j >= 0; j--)
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1, parent[i] = j;
        for(int i = 0; i < nums.size(); i++)
            if(dp[i] > dp[max_index])
                max_index = i;
        vector<int>res;
        while(max_index != -1)
            res.push_back(nums[max_index]), max_index = parent[max_index];
        return res;
    }
};

int main()
{
    Solution s;
    vector<int>nums = {1, 2, 3};
    vector<int>res = s.largestDivisibleSubset(nums);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
