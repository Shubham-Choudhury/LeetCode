// Link: https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int movesToMakeZigzag(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nums1 = nums, nums2 = nums;
        int res1 = 0, res2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (i > 0 && nums1[i] >= nums1[i - 1])
                {
                    res1 += nums1[i] - nums1[i - 1] + 1;
                    nums1[i] = nums1[i - 1] - 1;
                }
                if (i < n - 1 && nums1[i] >= nums1[i + 1])
                {
                    res1 += nums1[i] - nums1[i + 1] + 1;
                    nums1[i] = nums1[i + 1] - 1;
                }
            }
            else
            {
                if (i > 0 && nums2[i] >= nums2[i - 1])
                {
                    res2 += nums2[i] - nums2[i - 1] + 1;
                    nums2[i] = nums2[i - 1] - 1;
                }
                if (i < n - 1 && nums2[i] >= nums2[i + 1])
                {
                    res2 += nums2[i] - nums2[i + 1] + 1;
                    nums2[i] = nums2[i + 1] - 1;
                }
            }
        }
        return min(res1, res2);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    cout << s.movesToMakeZigzag(nums);
    return 0;
}
