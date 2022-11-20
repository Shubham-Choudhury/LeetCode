// Link: https://leetcode.com/problems/third-maximum-number/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;
        for (auto num : nums) {
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second && num < first) {
                third = second;
                second = num;
            } else if (num > third && num < second) {
                third = num;
            }
        }
        return third == LONG_MIN ? first : third;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 2, 3, 1};
    cout << s.thirdMax(nums) << endl;
    return 0;
}