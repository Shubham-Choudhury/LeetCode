// Link: https://leetcode.com/problems/reshape-the-matrix/?envType=study-plan&id=data-structure-i

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

int main(){
    vector<vector<int>> nums = {{1,2},{3,4}};
    int r = 1;
    int c = 4;
    Solution obj;
    vector<vector<int>> ans = obj.matrixReshape(nums, r, c);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}