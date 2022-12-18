// Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int median = nums[n / 2];
        int res = 0;
        for (int i = 0; i < n; ++ i)
            res += abs(nums[i] - median);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int res;

    // Output: 2
    nums = {1, 2, 3};
    res = sol.minMoves2(nums);
    cout << res << endl;

    // Output: 14
    nums = {1, 0, 0, 8, 6};
    res = sol.minMoves2(nums);
    cout << res << endl;

    return 0;
}
