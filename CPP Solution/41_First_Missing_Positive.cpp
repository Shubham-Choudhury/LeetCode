// Link: https://leetcode.com/problems/first-missing-positive/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = { 1, 2, 0 };
    cout << sol.firstMissingPositive(nums) << endl;

    return 0;
}
