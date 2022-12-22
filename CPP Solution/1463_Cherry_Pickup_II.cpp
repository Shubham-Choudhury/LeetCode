// Link: https://leetcode.com/problems/cherry-pickup-ii/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;


class Solution {
public:
    int dy[3] = {0, -1, 1};
    int dp[71][71][71];
    
    int ff(vector<vector<int>>& grid, int i, int c1, int c2) {
        int m = grid.size();
        int n = grid[0].size();
        if (i == m) return 0;
        if (c1 < 0 || c2 < 0 || c1 >= n || c2 >= n) return INT_MIN;
        if (dp[i][c1][c2] != -1) return dp[i][c1][c2];
        
        int maxAns = 0;
        
        for (int k=0; k<3; k++) {
            for (int r=0; r<3; r++) {
                maxAns = max(maxAns, ff(grid, i + 1, c1 + dy[k], c2 + dy[r]));
            }
        }
        
        maxAns += (c1 == c2) ? grid[i][c1] : grid[i][c1] + grid[i][c2];
        return dp[i][c1][c2] = maxAns;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        memset(dp, -1, sizeof dp);
        return ff(grid, 0, 0, n-1);
    }
};

int main(void) {
    Solution sol;
    vector<vector<int>> grid = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};
    int res = sol.cherryPickup(grid);
    cout << res << endl;
    return 0;
}
