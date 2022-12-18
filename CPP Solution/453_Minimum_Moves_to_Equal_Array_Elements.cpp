// Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int min = nums[0];
        for (int i = 1; i<n; i++) {
            if (nums[i] < min) {
                min = nums[i];
            }
        }
        int moves = 0;
        for (int i = 0; i<n; i++) {
            moves += nums[i] - min;
        }
        return moves;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    cout << s.minMoves(nums) << endl;
    return 0;
}
