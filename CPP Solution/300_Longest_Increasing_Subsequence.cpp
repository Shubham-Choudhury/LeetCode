// Link: https://leetcode.com/problems/longest-increasing-subsequence/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int x : nums) {
            auto it = lower_bound(dp.begin(), dp.end(), x);
            if (it == dp.end()) {
                dp.push_back(x);
            } else {
                *it = x;
            }
        }
        return dp.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << sol.lengthOfLIS(nums) << endl;
    return 0;
}