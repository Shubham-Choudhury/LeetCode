// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (nums[j] != nums[i]) {
                nums[++i] = nums[j];
            }
        }
        
        return i + 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int result;
    
    nums = {1,1,2};
    result = sol.removeDuplicates(nums);
    cout << result << endl;
    
    nums = {0,0,1,1,1,2,2,3,3,4};
    result = sol.removeDuplicates(nums);
    cout << result << endl;
    
    return 0;
}