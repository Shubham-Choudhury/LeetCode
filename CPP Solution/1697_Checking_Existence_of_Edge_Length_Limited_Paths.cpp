// Link: https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int m = queries.size();
        for (int i = 0; i < m; ++i) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        vector<bool> ans(m, false);
        vector<int> parent(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        int j = 0;
        for (int i = 0; i < m; ++i) {
            while (j < edgeList.size() && edgeList[j][2] < queries[i][2]) {
                int u = edgeList[j][0], v = edgeList[j][1];
                int pu = find(parent, u), pv = find(parent, v);
                if (pu != pv) {
                    parent[pu] = pv;
                }
                j++;
            }
            int u = queries[i][0], v = queries[i][1];
            int pu = find(parent, u), pv = find(parent, v);
            if (pu == pv) {
                ans[queries[i][3]] = true;
            }
        }
        return ans;
    }
    
    int find(vector<int>& parent, int u) {
        if (parent[u] != u) {
            parent[u] = find(parent, parent[u]);
        }
        return parent[u];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edgeList = {{0, 1, 10}, {1, 2, 5}, {2, 3, 9}, {3, 4, 13}};
    vector<vector<int>> queries = {{0, 4, 14}, {1, 4, 13}};
    vector<bool> ans = s.distanceLimitedPathsExist(5, edgeList, queries);
    for (bool b : ans) {
        cout << b << " ";
    }
    cout << endl;
    return 0;
}
