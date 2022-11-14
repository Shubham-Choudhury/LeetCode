// Link: https://leetcode.com/problems/number-of-islands/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(grid[i][j] == '1') {
            grid[i][j] = '0';
            if(i >= 1) {
                dfs(grid, i - 1, j);
            }
            if(j >= 1) {
                dfs(grid, i, j - 1);
            }
            if(i + 1 < grid.size()) {
                dfs(grid, i + 1, j);
            }
            if(j + 1 < grid[0].size()) {
                dfs(grid, i, j + 1);
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    cout << sol.numIslands(grid) << endl;
    return 0;
}