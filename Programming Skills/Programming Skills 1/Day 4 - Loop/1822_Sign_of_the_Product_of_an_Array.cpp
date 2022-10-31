// Link: https://leetcode.com/problems/sign-of-the-product-of-an-array/?envType=study-plan&id=programming-skills-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                return 0;
            }
            if (nums[i] < 0) {
                sign *= -1;
            }
        }
        return sign;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1, -2, -3, -4, 3, 2, 1};
    cout << solution.arraySign(nums) << endl;
    return 0;
}