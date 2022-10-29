// Link: https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsAllNumbers(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        unordered_set<int> rowSet;
        unordered_set<int> colSet;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                rowSet.insert(grid[i][j]);
                colSet.insert(grid[j][i]);
            }
            if (rowSet.size() != col || colSet.size() != col) {
                return false;
            }
            rowSet.clear();
            colSet.clear();
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{1, 2, 3, 4}, {2, 1, 4, 3}, {3, 4, 1, 2}, {4, 3, 2, 1}};
    cout << s.containsAllNumbers(grid) << endl;
    return 0;
}