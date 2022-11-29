// Link: https://leetcode.com/problems/combination-sum/?envType=study-plan&id=level-2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, path, result);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> candidates = {2, 3, 6, 7};
    vector<vector<int>> result = s.combinationSum(candidates, 7);
    for (auto& v : result) {
        for (auto& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}