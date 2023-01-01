// Link: https://leetcode.com/problems/maximum-score-of-a-good-subarray/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = nums[k];
        int l = k, r = k;
        int mn = nums[k];
        while (l > 0 || r < n - 1) {
            if (l == 0) {
                r++;
            } else if (r == n - 1) {
                l--;
            } else if (nums[l - 1] < nums[r + 1]) {
                r++;
            } else {
                l--;
            }
            mn = min(mn, min(nums[l], nums[r]));
            ans = max(ans, mn * (r - l + 1));
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int k, ans;

    // Output: 14
    nums = {1, 4, 3, 7, 4, 5}, k = 3;
    ans = sol.maximumScore(nums, k);
    cout << ans << endl;

    // Output: 15
    nums = {5, 5, 4, 5, 4, 1, 1, 1}, k = 0;
    ans = sol.maximumScore(nums, k);
    cout << ans << endl;

    return 0;
}
