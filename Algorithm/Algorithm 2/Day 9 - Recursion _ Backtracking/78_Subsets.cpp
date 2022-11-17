// Link: https://leetcode.com/problems/subsets/?envType=study-plan&id=algorithm-ii

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        subsets(nums, 0, subset, result);
        return result;
    }

    private:
    void subsets(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(subset);
            return;
        }
        subsets(nums, index + 1, subset, result);
        subset.push_back(nums[index]);
        subsets(nums, index + 1, subset, result);
        subset.pop_back();
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = s.subsets(nums);
    for (vector<int> subset : result) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}