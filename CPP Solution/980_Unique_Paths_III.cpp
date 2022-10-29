// Link: https://leetcode.com/problems/unique-paths-iii/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int startRow = 0;
        int startCol = 0;
        int empty = 1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                } else if (grid[i][j] == 0) {
                    empty++;
                }
            }
        }
        return uniquePathsIII(grid, startRow, startCol, empty);
    }
private:
    int uniquePathsIII(vector<vector<int>>& grid, int row, int col, int empty) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == -1) {
            return 0;
        }
        if (grid[row][col] == 2) {
            return empty == 0 ? 1 : 0;
        }
        grid[row][col] = -1;
        int paths = uniquePathsIII(grid, row + 1, col, empty - 1) +
                    uniquePathsIII(grid, row - 1, col, empty - 1) +
                    uniquePathsIII(grid, row, col + 1, empty - 1) +
                    uniquePathsIII(grid, row, col - 1, empty - 1);
        grid[row][col] = 0;
        return paths;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
    cout << s.uniquePathsIII(grid) << endl;
    return 0;
}