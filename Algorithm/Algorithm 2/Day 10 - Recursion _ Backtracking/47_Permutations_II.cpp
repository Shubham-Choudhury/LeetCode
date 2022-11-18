// Link: https://leetcode.com/problems/permutations-ii/?envType=study-plan&id=algorithm-ii

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, used, path, result);
        return result;
    }
    
    void dfs(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& result) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, used, path, result);
            path.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result = s.permuteUnique(nums);
    for (auto& v : result) {
        for (auto& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}