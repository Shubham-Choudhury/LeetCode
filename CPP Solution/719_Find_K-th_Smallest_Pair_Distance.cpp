// Link: https://leetcode.com/problems/find-k-th-smallest-pair-distance/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = nums[n - 1] - nums[0];
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for (int i = 0, j = 0; i < n; i++)
            {
                while (j < n && nums[j] - nums[i] <= mid)
                    j++;
                cnt += j - i - 1;
            }
            if (cnt < k)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int k;

    // Output: 0
    nums = {1, 3, 1}, k = 1;
    cout << sol.smallestDistancePair(nums, k) << endl;

    // Output: 2
    nums = {1, 6, 1}, k = 3;
    cout << sol.smallestDistancePair(nums, k) << endl;

    return 0;
}