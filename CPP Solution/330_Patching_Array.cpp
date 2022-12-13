// Link: https://leetcode.com/problems/patching-array/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;
        int added = 0, i = 0;
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i];
                i++;
            } else {
                miss += miss;
                added++;
            }
        }
        return added;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int n, res;
    
    // Output: 1
    nums = {1, 3}, n = 6;
    res = sol.minPatches(nums, n);
    cout << res << endl;
    
    // Output: 2
    nums = {1, 5, 10}, n = 20;
    res = sol.minPatches(nums, n);
    cout << res << endl;
    
    // Output: 0
    nums = {1, 2, 2}, n = 5;
    res = sol.minPatches(nums, n);
    cout << res << endl;
    
    // Output: 1
    nums = {1, 2, 31, 33}, n = 2147483647;
    res = sol.minPatches(nums, n);
    cout << res << endl;
    
    return 0;
}