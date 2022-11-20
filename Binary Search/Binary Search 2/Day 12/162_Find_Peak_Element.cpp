// Link: https://leetcode.com/problems/find-peak-element/?envType=study-plan&id=binary-search-ii

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.findPeakElement(nums) << endl;
    return 0;
}