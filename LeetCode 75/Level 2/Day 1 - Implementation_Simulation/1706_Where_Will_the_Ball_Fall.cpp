// Link: https://leetcode.com/problems/where-will-the-ball-fall/?envType=study-plan&id=level-2

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) {
            int x = 0, y = i;
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
                res[i] = y;
            }
        }
        return res;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> grid = {{1, 1, 1, -1, -1}, {1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1}, {1, 1, 1, 1, -1}, {-1, -1, -1, -1, -1}};
    vector<int> res = obj.findBall(grid);
    for (int i : res) {
        cout << i << " ";
    }
    return 0;
}