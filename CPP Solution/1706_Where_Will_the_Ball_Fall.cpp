// Link: https://leetcode.com/problems/where-will-the-ball-fall/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> result(n, -1);
        
        for (int i = 0; i < n; i++) {
            int x = 0;
            int y = i;
            while (x < m) {
                if (grid[x][y] == 1) {
                    if (y == n - 1 || grid[x][y + 1] == -1) {
                        break;
                    }
                    y++;
                } else {
                    if (y == 0 || grid[x][y - 1] == 1) {
                        break;
                    }
                    y--;
                }
                x++;
            }
            if (x == m) {
                result[i] = y;
            }
        }
        
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{1, 1, 1, -1, -1}, {1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1}, {1, 1, 1, 1, -1}, {-1, -1, -1, -1, -1}};
    vector<int> result = s.findBall(grid);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}