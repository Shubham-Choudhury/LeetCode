// Link: https://leetcode.com/problems/shortest-bridge/?envType=study-plan&id=graph-i

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        int res = 0;
        bool found = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 1) {
                    dfs(A, i, j);
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                if (x > 0 && A[x - 1][y] == 1) {
                    return res;
                }
                if (x < m - 1 && A[x + 1][y] == 1) {
                    return res;
                }
                if (y > 0 && A[x][y - 1] == 1) {
                    return res;
                }
                if (y < n - 1 && A[x][y + 1] == 1) {
                    return res;
                }
                if (x > 0 && A[x - 1][y] == 0) {
                    A[x - 1][y] = 2;
                    q.push({x - 1, y});
                }
                if (x < m - 1 && A[x + 1][y] == 0) {
                    A[x + 1][y] = 2;
                    q.push({x + 1, y});
                }
                if (y > 0 && A[x][y - 1] == 0) {
                    A[x][y - 1] = 2;
                    q.push({x, y - 1});
                }
                if (y < n - 1 && A[x][y + 1] == 0) {
                    A[x][y + 1] = 2;
                    q.push({x, y + 1});
                }
            }
            res++;
        }
        return res;
    }

    void dfs(vector<vector<int>>& A, int i, int j) {
        int m = A.size();
        int n = A[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || A[i][j] != 1) {
            return;
        }
        A[i][j] = 2;
        dfs(A, i - 1, j);
        dfs(A, i + 1, j);
        dfs(A, i, j - 1);
        dfs(A, i, j + 1);
    }
};

int main() {
    Solution s;
    vector<vector<int>> A = {{0, 1}, {1, 0}};
    int res = s.shortestBridge(A);
    return 0;
}