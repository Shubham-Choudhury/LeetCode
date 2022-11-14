// Link: https://leetcode.com/problems/minimum-absolute-sum-difference/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> nums1Sorted = nums1;
        sort(nums1Sorted.begin(), nums1Sorted.end());
        int maxDiff = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            sum = (sum + diff) % 1000000007;
            int j = lower_bound(nums1Sorted.begin(), nums1Sorted.end(), nums2[i]) - nums1Sorted.begin();
            if (j < n) {
                maxDiff = max(maxDiff, diff - (nums1Sorted[j] - nums2[i]));
            }
            if (j > 0) {
                maxDiff = max(maxDiff, diff - (nums2[i] - nums1Sorted[j - 1]));
            }
        }
        return (sum - maxDiff + 1000000007) % 1000000007;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 7, 5}, nums2 = {2, 3, 5};
    cout << sol.minAbsoluteSumDiff(nums1, nums2) << endl;
    return 0;
}