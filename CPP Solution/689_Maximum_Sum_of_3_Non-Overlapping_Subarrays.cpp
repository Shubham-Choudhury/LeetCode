// Link: https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        vector<int> left(n, 0);
        int maxSum = sums[k] - sums[0];
        for (int i = k; i < n; i++) {
            if (sums[i + 1] - sums[i + 1 - k] > maxSum) {
                maxSum = sums[i + 1] - sums[i + 1 - k];
                left[i] = i + 1 - k;
            } else {
                left[i] = left[i - 1];
            }
        }
        vector<int> right(n, n - k);
        maxSum = sums[n] - sums[n - k];
        for (int i = n - k - 1; i >= 0; i--) {
            if (sums[i + k] - sums[i] >= maxSum) {
                maxSum = sums[i + k] - sums[i];
                right[i] = i;
            } else {
                right[i] = right[i + 1];
            }
        }
        vector<int> res(3, 0);
        maxSum = 0;
        for (int i = k; i <= n - 2 * k; i++) {
            int l = left[i - 1];
            int r = right[i + k];
            int sum = (sums[i + k] - sums[i]) + (sums[l + k] - sums[l]) + (sums[r + k] - sums[r]);
            if (sum > maxSum) {
                maxSum = sum;
                res[0] = l;
                res[1] = i;
                res[2] = r;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 1, 2, 6, 7, 5, 1};
    vector<int> res = sol.maxSumOfThreeSubarrays(nums, 2);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
