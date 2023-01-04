// Link: https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            string s = "";
            for (int j = 0; j < m; j++)
                s += to_string(matrix[i][j]);
            mp[s]++;
        }
        int mx = 0;
        for (auto &x : mp)
            mx = max(mx, x.second);
        for (int i = 0; i < n; i++)
        {
            string s = "";
            for (int j = 0; j < m; j++)
                s += to_string(1 - matrix[i][j]);
            mp[s]++;
        }
        for (auto &x : mp)
            mx = max(mx, x.second);
        return mx;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{0, 1}, {1, 1}};
    cout << sol.maxEqualRowsAfterFlips(matrix) << endl;
    return 0;
}

