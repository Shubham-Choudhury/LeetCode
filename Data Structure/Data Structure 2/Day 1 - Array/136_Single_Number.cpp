// Link: https://leetcode.com/problems/single-number/?envType=study-plan&id=data-structure-ii

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result ^= nums[i];
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 2, 1};
    cout << s.singleNumber(nums) << endl;
    return 0;
}