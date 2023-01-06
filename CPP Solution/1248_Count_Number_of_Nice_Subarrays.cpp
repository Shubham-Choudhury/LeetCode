// Link: https://leetcode.com/problems/count-number-of-nice-subarrays/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int res = 0;
        int n = nums.size();
        vector<int> odd;
        odd.push_back(-1);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 1)
                odd.push_back(i);
        }
        odd.push_back(n);
        for (int i = 1; i + k < odd.size(); i++)
        {
            res += (odd[i] - odd[i - 1]) * (odd[i + k] - odd[i + k - 1]);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << s.numberOfSubarrays(nums, k) << endl;
    return 0;
}
