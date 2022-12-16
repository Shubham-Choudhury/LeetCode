// Link: https://leetcode.com/problems/combination-sum-iii/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, k, n, 1);
        return res;
    }
    void dfs(vector<vector<int>> &res, vector<int> &path, int k, int n, int start)
    {
        if (path.size() == k && n == 0)
        {
            res.push_back(path);
            return;
        }
        for (int i = start; i <= 9; i++)
        {
            path.push_back(i);
            dfs(res, path, k, n - i, i + 1);
            path.pop_back();
        }
    }
};

int main()
{
    Solution a;
    vector<vector<int>> res = a.combinationSum3(3, 7);
    for (auto &a : res)
    {
        for (auto &b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    res = a.combinationSum3(3, 9);
    for (auto &a : res)
    {
        for (auto &b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}
