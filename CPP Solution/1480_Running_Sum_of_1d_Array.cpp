// Link: https://leetcode.com/problems/running-sum-of-1d-array/?envType=study-plan&id=level-1

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sums(nums.size());
        sums[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sums[i] = sums[i - 1] + nums[i];
        }
        return sums;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> sums = s.runningSum(nums);
    for (int sum : sums) {
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}