// Link: https://leetcode.com/problems/subsets-ii/?envType=study-plan&id=algorithm-ii

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        subsetsWithDup(nums, 0, subset, result);
        return result;
    }
    
    private:
    void subsetsWithDup(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& result) {
        result.push_back(subset);
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }
            subset.push_back(nums[i]);
            subsetsWithDup(nums, i + 1, subset, result);
            subset.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = s.subsetsWithDup(nums);
    for (vector<int> subset : result) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}