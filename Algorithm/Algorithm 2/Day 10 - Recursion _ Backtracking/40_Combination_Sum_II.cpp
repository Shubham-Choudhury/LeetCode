// Link: https://leetcode.com/problems/combination-sum-ii/?envType=study-plan&id=algorithm-ii

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, path, result);
        return result;
    }
    
    void dfs(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                break;
            }
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, path, result);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> result = s.combinationSum2(candidates, 8);
    for (auto& v : result) {
        for (auto& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}