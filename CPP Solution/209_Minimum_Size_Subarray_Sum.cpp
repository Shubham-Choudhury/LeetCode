// Link: https://leetcode.com/problems/minimum-size-subarray-sum/?envType=study-plan&id=binary-search-ii

#include <iostream>
#include <vector>
using namespace std;

#define INT_MAX 2147483647

class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = 0;
        int sum = 0;
        int ans = INT_MAX;
        while (high < n)
        {
            sum += nums[high];
            while (sum >= s)
            {
                ans = min(ans, high - low + 1);
                sum -= nums[low];
                low++;
            }
            high++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int s = 7;
    cout << sol.minSubArrayLen(s, nums) << endl;
    return 0;
}