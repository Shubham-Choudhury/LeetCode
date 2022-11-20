// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else if (nums[mid] < nums[high])
            {
                high = mid;
            }
            else
            {
                high--;
            }
        }
        return nums[low];
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 5};
    cout << s.findMin(nums) << endl;
    return 0;
}