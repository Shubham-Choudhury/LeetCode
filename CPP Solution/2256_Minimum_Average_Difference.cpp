// Link: https://leetcode.com/problems/minimum-average-difference/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        long totalsum = 0, currentsum = 0;
        int n = nums.size();

        // calc totalsum
        for (auto i : nums)
            totalsum += i;

        int mini = INT_MAX;
        int indexans = 0;

        for (int i = 0; i < n; i++)
        {
            currentsum += nums[i];
            int avg1 = currentsum / (i + 1);
            if (i == n - 1)
            {
                if (avg1 < mini)
                    return n - 1;
                else
                    break;
            }
            int avg2 = (totalsum - currentsum) / (n - i - 1);

            if (abs(avg1 - avg2) < mini)
            {
                mini = abs(avg1 - avg2);
                indexans = i;
            }
        }

        return indexans;
    }
};


int main()
{
    Solution sol;
    vector<int> nums;
    int result;

    // Test Case 1
    nums = {3, 7, 5, 6, 3};
    result = sol.minimumAverageDifference(nums);
    cout << result << endl;

    // Test Case 2
    nums = {1, 2, 3, 4, 5};
    result = sol.minimumAverageDifference(nums);
    cout << result << endl;

    return 0;
}