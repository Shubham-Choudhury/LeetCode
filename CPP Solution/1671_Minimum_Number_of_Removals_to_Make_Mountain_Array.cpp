// Link: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1);
        vector<int> lds(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j])
                    lds[i] = max(lds[i], lds[j] + 1);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (lis[i] > 1 && lds[i] > 1)
                ans = max(ans, lis[i] + lds[i] - 1);
        }
        return n - ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 1};
    cout << s.minimumMountainRemovals(nums) << endl;
    return 0;
}
