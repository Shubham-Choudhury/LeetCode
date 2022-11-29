// Link: https://leetcode.com/problems/permutations/

#include <iostream>
#include <vector>
#include <algorithm>
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

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = s.permute(nums);
    for (auto v : res) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
