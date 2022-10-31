// Link: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <sstream>
#include <map>
using namespace std;


class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = 0;
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                if (x == n - 1 && y == m - 1) {
                    return steps;
                }
                for (int j = 0; j < 4; j++) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        continue;
                    }
                    int nk = visited[x][y] + grid[nx][ny];
                    if (nk > k || nk >= visited[nx][ny] && visited[nx][ny] != -1) {
                        continue;
                    }
                    visited[nx][ny] = nk;
                    q.push({nx, ny});
                }
            }
            steps++;
        }
        return -1;
    }
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
    cout << s.shortestPath(grid, 1) << endl;
    return 0;
}