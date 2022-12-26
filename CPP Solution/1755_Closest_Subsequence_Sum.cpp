// Link: https://leetcode.com/problems/closest-subsequence-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAbsDifference(vector<int> &nums, int goal)
    {
        int n = nums.size();
        vector<int> left(1 << (n / 2));
        vector<int> right(1 << (n - n / 2));
        for (int i = 0; i < (1 << (n / 2)); i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                if (i & (1 << j))
                {
                    left[i] += nums[j];
                }
            }
        }
        for (int i = 0; i < (1 << (n - n / 2)); i++)
        {
            for (int j = 0; j < n - n / 2; j++)
            {
                if (i & (1 << j))
                {
                    right[i] += nums[n / 2 + j];
                }
            }
        }
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        int result = INT_MAX;
        for (int i = 0; i < (1 << (n - n / 2)); i++)
        {
            int target = goal - right[i];
            int index = lower_bound(left.begin(), left.end(), target) - left.begin();
            if (index < (1 << (n / 2)))
            {
                result = min(result, abs(left[index] - target));
            }
            if (index > 0)
            {
                result = min(result, abs(left[index - 1] - target));
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int goal, result;

    // Output: 2
    nums = {5, -7, 3, 5}, goal = 6;
    result = sol.minAbsDifference(nums, goal);
    cout << result << endl;

    // Output: 0
    nums = {7, -9, 15, -2}, goal = -5;
    result = sol.minAbsDifference(nums, goal);
    cout << result << endl;

    // Output: 1
    nums = {1, 2, 3}, goal = -7;
    result = sol.minAbsDifference(nums, goal);
    cout << result << endl;

    return 0;
}
