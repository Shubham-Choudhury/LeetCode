// Link: https://leetcode.com/problems/frequency-of-the-most-frequent-element/?envType=study-plan&id=binary-search-ii

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = 1;
        int left = 0;
        long long sum = 0;
        for (int right = 1; right < nums.size(); right++) {
            sum += (long long)(nums[right] - nums[right - 1]) * (right - left);
            while (sum > k) {
                sum -= nums[right] - nums[left];
                left++;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 2, 4};
    int k = 5;
    Solution sol;
    cout << sol.maxFrequency(nums, k) << endl;
    return 0;
}