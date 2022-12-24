// Link: https://leetcode.com/problems/get-the-maximum-score/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        long long sum1 = 0, sum2 = 0;
        while (i < nums1.size() || j < nums2.size()) {
            if (i < nums1.size() && (j == nums2.size() || nums1[i] < nums2[j])) {
                sum1 += nums1[i++];
            } else if (j < nums2.size() && (i == nums1.size() || nums1[i] > nums2[j])) {
                sum2 += nums2[j++];
            } else {
                sum1 = sum2 = max(sum1, sum2) + nums1[i];
                i++;
                j++;
            }
        }
        return max(sum1, sum2) % 1000000007;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {2,4,5,8,10};
    vector<int> nums2 = {4,6,8,9};
    cout << s.maxSum(nums1, nums2) << endl;
    return 0;
}
