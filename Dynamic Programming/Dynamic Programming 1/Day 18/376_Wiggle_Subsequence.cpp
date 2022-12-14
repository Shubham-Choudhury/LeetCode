// Link: https://leetcode.com/problems/wiggle-subsequence/?envType=study-plan&id=dynamic-programming-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> up(n, 0);
        vector<int> down(n, 0);
        up[0] = 1;
        down[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];
            } else if (nums[i] < nums[i - 1]) {
                up[i] = up[i - 1];
                down[i] = up[i - 1] + 1;
            } else {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(up[n - 1], down[n - 1]);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 7, 4, 9, 2, 5};
    cout << sol.wiggleMaxLength(nums) << endl;
    return 0;
}