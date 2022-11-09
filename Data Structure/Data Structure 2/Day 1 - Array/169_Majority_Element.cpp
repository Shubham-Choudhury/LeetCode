// Link: https://leetcode.com/problems/majority-element/?envType=study-plan&id=data-structure-ii

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                result = nums[i];
                count++;
            } else {
                if (result == nums[i]) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << s.majorityElement(nums) << endl;
    return 0;
}