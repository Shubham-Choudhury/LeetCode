// Link: https://leetcode.com/problems/non-decreasing-array/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size() && count <= 1; i++) {
            if (nums[i - 1] > nums[i]) {
                count++;
                if (i - 2 < 0 || nums[i - 2] <= nums[i]) {
                    nums[i - 1] = nums[i];
                } else {
                    nums[i] = nums[i - 1];
                }
            }
        }
        return count <= 1;
    }
};

int main(void) {
    Solution sol;
    vector<int> nums = {4, 2, 3};
    cout << sol.checkPossibility(nums) << endl;
    return 0;
}
