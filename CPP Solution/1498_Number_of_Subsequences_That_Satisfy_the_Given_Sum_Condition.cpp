// Link: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> pow2(n, 1);
        for (int i = 1; i < n; i++)
            pow2[i] = (pow2[i - 1] * 2) % 1000000007;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] * 2 > target)
                break;
            int low = i, high = n - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums[i] + nums[mid] <= target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            ans = (ans + pow2[high - i]) % 1000000007;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 5, 6, 7};
    cout << s.numSubseq(nums, 9);
    return 0;
}