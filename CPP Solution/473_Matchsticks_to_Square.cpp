// Link: https://leetcode.com/problems/matchsticks-to-square/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<int> buffer;
    int quarter;
    bool make4(const vector<int> &nums, int target, int k)
    {
        if (target == 0)
        {
            vector<int> nums_c;
            int j = 0;
            for (int i = nums.size() - 1; i >= 0; --i)
                if (j < buffer.size() && buffer[j] == nums[i])
                    j++;
                else
                    nums_c.push_back(nums[i]);
            return make2(buffer, quarter, buffer.size() - 1) && make2(nums_c, quarter, nums_c.size() - 1);
        }
        if (k < 0 || target < 0)
            return false;
        buffer.push_back(nums[k]);
        int ismade = make4(nums, target - nums[k], k - 1);
        buffer.pop_back();
        if (ismade)
            return true;
        return make4(nums, target, k - 1);
    }
    bool make2(const vector<int> &nums, int target, int k)
    {
        if (target == 0)
            return true;
        if (target < 0 || k < 0)
            return false;
        return make2(nums, target - nums[k], k - 1) || make2(nums, target, k - 1);
    }

public:
    bool makesquare(vector<int> &nums)
    {
        if (nums.empty())
            return false;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];
        if (sum % 4 != 0)
            return false;
        quarter = sum / 4;
        return make4(nums, sum / 2, nums.size() - 1);
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 1, 2, 2, 2};
    cout << s.makesquare(v) << endl;
    return 0;
}
