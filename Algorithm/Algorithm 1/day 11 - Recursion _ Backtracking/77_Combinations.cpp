// Link: https://leetcode.com/problems/combinations/?envType=study-plan&id=algorithm-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(res, temp, n, k, 1);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& temp, int n, int k, int start) {
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }
        for (int i = start; i <= n; i++) {
            temp.push_back(i);
            helper(res, temp, n, k, i + 1);
            temp.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    int n = 4;
    int k = 2;
    vector<vector<int>> res = sol.combine(n, k);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}