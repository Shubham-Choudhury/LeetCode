// Link: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool dfs(vector<int> groups, int row, vector<int> nums, int target)
    {
        if (row < 0)
            return true;
        int v = nums[row--];
        for (int i = 0; i < groups.size(); i++)
        {
            if (groups[i] + v <= target)
            {
                groups[i] += v;
                if (dfs(groups, row, nums, target))
                    return true;
                groups[i] -= v;
            }
            if (groups[i] == 0)
                break;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        if (sum % k)
            return false;
        int target = sum / k;
        sort(nums.begin(), nums.end());
        int row = nums.size() - 1;
        if (nums[row] > target)
            return false;
        while (row >= 0 && nums[row] == target)
        {
            row--;
            k--;
        }
        return dfs(vector<int>(k), row, nums, target);
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    cout << obj.canPartitionKSubsets(nums, 4) << endl;
    return 0;
}
