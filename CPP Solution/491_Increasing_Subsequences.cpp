// Link: https://leetcode.com/problems/increasing-subsequences/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> v;
        dfs(nums, 0, v, s);
        vector<vector<int>> res;
        for(auto v : s) {
            res.push_back(v);
        }
        return res;
    }
private:
    void dfs(vector<int>& nums, int start, vector<int>& v, set<vector<int>>& s) {
        if(v.size() >= 2) {
            s.insert(v);
        }
        for(int i = start; i < nums.size(); i++) {
            if(v.empty() || nums[i] >= v.back()) {
                v.push_back(nums[i]);
                dfs(nums, i + 1, v, s);
                v.pop_back();
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> v = {4, 6, 7, 7};
    vector<vector<int>> res = s.findSubsequences(v);
    for(auto v : res) {
        for(auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
