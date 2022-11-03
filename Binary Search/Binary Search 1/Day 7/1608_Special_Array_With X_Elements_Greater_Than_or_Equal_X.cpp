// Link: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/?envType=study-plan&id=binary-search-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] >= i) {
                    count++;
                }
            }
            if (count == i) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 5};
    int res = s.specialArray(nums);
    return 0;
}