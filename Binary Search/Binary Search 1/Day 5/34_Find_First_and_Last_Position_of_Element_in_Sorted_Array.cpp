// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/?envType=study-plan&id=binary-search-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                break;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (left > right) {
            return {-1, -1};
        }
        int leftBound = mid;
        int rightBound = mid;
        while (leftBound > 0 && nums[leftBound - 1] == target) {
            leftBound--;
        }
        while (rightBound < nums.size() - 1 && nums[rightBound + 1] == target) {
            rightBound++;
        }
        return {leftBound, rightBound};
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> result = s.searchRange(nums, 8);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}