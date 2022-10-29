// Link: https://leetcode.com/problems/find-pivot-index/?envType=study-plan&id=level-1

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (leftSum == sum - leftSum - nums[i]) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << s.pivotIndex(nums) << endl;
    return 0;
}