// Link: https://leetcode.com/problems/trapping-rain-water-ii/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], i * n});
            pq.push({heightMap[i][n - 1], i * n + n - 1});
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; j++) {
            pq.push({heightMap[0][j], j});
            pq.push({heightMap[m - 1][j], (m - 1) * n + j});
            visited[0][j] = true;
            visited[m - 1][j] = true;
        }
        int res = 0;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int h = p.first;
            int i = p.second / n;
            int j = p.second % n;
            if (i > 0 && !visited[i - 1][j]) {
                res += max(0, h - heightMap[i - 1][j]);
                pq.push({max(h, heightMap[i - 1][j]), (i - 1) * n + j});
                visited[i - 1][j] = true;
            }
            if (i < m - 1 && !visited[i + 1][j]) {
                res += max(0, h - heightMap[i + 1][j]);
                pq.push({max(h, heightMap[i + 1][j]), (i + 1) * n + j});
                visited[i + 1][j] = true;
            }
            if (j > 0 && !visited[i][j - 1]) {
                res += max(0, h - heightMap[i][j - 1]);
                pq.push({max(h, heightMap[i][j - 1]), i * n + j - 1});
                visited[i][j - 1] = true;
            }
            if (j < n - 1 && !visited[i][j + 1]) {
                res += max(0, h - heightMap[i][j + 1]);
                pq.push({max(h, heightMap[i][j + 1]), i * n + j + 1});
                visited[i][j + 1] = true;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> heightMap;
    int res;

    // Output: 4
    heightMap = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}
    };
    res = sol.trapRainWater(heightMap);
    cout << res << endl;

    return 0;
}