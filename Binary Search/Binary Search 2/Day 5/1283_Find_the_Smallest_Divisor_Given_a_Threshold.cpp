// Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/?envType=study-plan&id=binary-search-ii

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = 1e6;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                sum += (nums[i] + mid - 1) / mid;
            }
            if (sum > threshold) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,5,9};
    int threshold = 6;
    cout << s.smallestDivisor(nums, threshold) << endl;
    return 0;
}