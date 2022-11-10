// Link: https://leetcode.com/problems/find-peak-element/?envType=study-plan&id=algorithm-ii

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
    Solution obj;
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    cout << obj.findPeakElement(nums);
    return 0;
}