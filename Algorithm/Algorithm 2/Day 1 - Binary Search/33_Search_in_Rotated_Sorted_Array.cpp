// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/?envType=study-plan&id=algorithm-ii

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r){
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            if (nums[l] <= nums[mid]){
                if (nums[l] <= target && target < nums[mid]) r = mid - 1;
                else l = mid + 1;
            }
            else{
                if (nums[mid] < target && target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << solution.search(nums, 0) << endl;
    cout << solution.search(nums, 3) << endl;
    return 0;
}