// Link: https://leetcode.com/problems/rotting-oranges/?envType=study-plan&id=algorithm-i

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                } else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if(fresh == 0) {
            return 0;
        }
        int time = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                if(x - 1 >= 0 && grid[x - 1][y] == 1) {
                    grid[x - 1][y] = 2;
                    fresh--;
                    q.push({x - 1, y});
                }
                if(y - 1 >= 0 && grid[x][y - 1] == 1) {
                    grid[x][y - 1] = 2;
                    fresh--;
                    q.push({x, y - 1});
                }
                if(x + 1 < m && grid[x + 1][y] == 1) {
                    grid[x + 1][y] = 2;
                    fresh--;
                    q.push({x + 1, y});
                }
                if(y + 1 < n && grid[x][y + 1] == 1) {
                    grid[x][y + 1] = 2;
                    fresh--;
                    q.push({x, y + 1});
                }
            }
            time++;
        }
        if(fresh == 0) {
            return time - 1;
        } else {
            return -1;
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << s.orangesRotting(grid) << endl;
    return 0;
}