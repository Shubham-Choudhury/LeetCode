// Link: https://leetcode.com/problems/increasing-triplet-subsequence/?envType=study-plan&id=data-structure-ii

#include <iostream>
#include <vector>
using namespace std;

#define INT_MAX 2147483647

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        int first = INT_MAX;
        int second = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= first) {
                first = nums[i];
            } else if (nums[i] <= second) {
                second = nums[i];
            } else {
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << s.increasingTriplet(nums) << endl;
    return 0;
}