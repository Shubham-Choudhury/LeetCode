// Link: https://leetcode.com/problems/count-sub-islands/?envType=study-plan&id=graph-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1) {
                    bool flag = true;
                    dfs(grid1, grid2, i, j, flag);
                    if (flag) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool& flag) {
        if (i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size() || grid2[i][j] == 0) {
            return;
        }
        if (grid1[i][j] == 0) {
            flag = false;
        }
        grid2[i][j] = 0;
        dfs(grid1, grid2, i - 1, j, flag);
        dfs(grid1, grid2, i + 1, j, flag);
        dfs(grid1, grid2, i, j - 1, flag);
        dfs(grid1, grid2, i, j + 1, flag);
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid1 = {{1,1,1,0,0},
                                 {0,1,1,1,1},
                                 {0,0,0,0,0},
                                 {1,0,0,0,0},
                                 {1,1,0,1,1}};
    vector<vector<int>> grid2 = {{1,1,1,0,0},
                                 {0,0,1,1,1},
                                 {0,1,0,0,0},
                                 {1,0,1,0,0},
                                 {1,1,0,1,1}};
    cout << solution.countSubIslands(grid1, grid2) << endl;
    return 0;
}