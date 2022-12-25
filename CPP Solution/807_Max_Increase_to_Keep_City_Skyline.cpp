// Link: https://leetcode.com/problems/max-increase-to-keep-city-skyline/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row(n, 0);
        vector<int> col(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += min(row[i], col[j]) - grid[i][j];
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}};
    cout << sol.maxIncreaseKeepingSkyline(grid) << endl;
    return 0;
}