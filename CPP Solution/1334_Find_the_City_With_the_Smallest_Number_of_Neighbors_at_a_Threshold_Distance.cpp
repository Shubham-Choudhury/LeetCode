// Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int ans = 0;
        int min_neigh = n;
        for (int i = 0; i < n; i++) {
            int neigh = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    neigh++;
                }
            }
            if (neigh <= min_neigh) {
                min_neigh = neigh;
                ans = i;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    int distanceThreshold = 4;
    cout << sol.findTheCity(4, edges, distanceThreshold) << endl;
    return 0;
}
