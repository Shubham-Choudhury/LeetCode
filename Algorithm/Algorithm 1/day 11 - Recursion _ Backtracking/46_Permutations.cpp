// Link: https://leetcode.com/problems/permutations/?envType=study-plan&id=algorithm-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        helper(res, temp, nums, visited);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, vector<bool>& visited) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])
                continue;
            temp.push_back(nums[i]);
            visited[i] = true;
            helper(res, temp, nums, visited);
            temp.pop_back();
            visited[i] = false;
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = { 1, 2, 3 };
    vector<vector<int>> res = sol.permute(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}