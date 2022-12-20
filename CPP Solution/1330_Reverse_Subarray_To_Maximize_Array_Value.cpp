// Link: https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int maxDiff = 0;
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        for (int i = 0; i < n - 1; i++) {
            res += abs(nums[i] - nums[i + 1]);
            maxDiff = max(maxDiff, abs(nums[0] - nums[i + 1]) - abs(nums[i] - nums[i + 1]));
            maxDiff = max(maxDiff, abs(nums[n - 1] - nums[i]) - abs(nums[i] - nums[i + 1]));
            minVal = min(minVal, max(nums[i], nums[i + 1]));
            maxVal = max(maxVal, min(nums[i], nums[i + 1]));
        }
        return res + max(maxDiff, 2 * (maxVal - minVal));
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    
    nums = {2,3,1,5,4};
    cout << sol.maxValueAfterReverse(nums) << endl;
    
    nums = {2,4,9,24,2,1,10};
    cout << sol.maxValueAfterReverse(nums) << endl;
    
    nums = {1,3,5,4,7};
    cout << sol.maxValueAfterReverse(nums) << endl;
    
    return 0;
}
