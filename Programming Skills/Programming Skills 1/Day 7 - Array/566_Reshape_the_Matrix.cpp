// Link: https://leetcode.com/problems/reshape-the-matrix/?envType=study-plan&id=programming-skills-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        if (m * n != r * c) {
            return nums;
        }
        vector<vector<int>> ans(r, vector<int>(c));
        int i = 0;
        int j = 0;
        for (int k = 0; k < m; k++) {
            for (int l = 0; l < n; l++) {
                ans[i][j] = nums[k][l];
                j++;
                if (j == c) {
                    j = 0;
                    i++;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> nums = {{1, 2}, {3, 4}};
    int r = 1;
    int c = 4;
    vector<vector<int>> res = s.matrixReshape(nums, r, c);
    return 0;
}