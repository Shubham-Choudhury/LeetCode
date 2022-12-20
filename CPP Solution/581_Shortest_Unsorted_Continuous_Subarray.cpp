// Link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_num = INT_MIN;
        int min_num = INT_MAX;
        int left = -1;
        int right = -1;
        for (int i = 0; i < n; ++i) {
            if (max_num > nums[i]) {
                right = i;
            } else {
                max_num = nums[i];
            }
            if (min_num < nums[n - 1 - i]) {
                left = n - 1 - i;
            } else {
                min_num = nums[n - 1 - i];
            }
        }
        return right == -1 ? 0 : right - left + 1;
    }
};

int main(void) {
    Solution sol;
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    cout << sol.findUnsortedSubarray(nums) << endl;
    return 0;
}
