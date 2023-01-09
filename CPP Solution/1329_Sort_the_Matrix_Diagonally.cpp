// Link: https://leetcode.com/problems/sort-the-matrix-diagonally/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; i++) {
            int j = 0;
            int k = i;
            vector<int> v;
            while (k < m && j < n) {
                v.push_back(mat[k][j]);
                k++;
                j++;
            }
            sort(v.begin(), v.end());
            k = i;
            j = 0;
            int idx = 0;
            while (k < m && j < n) {
                mat[k][j] = v[idx];
                k++;
                j++;
                idx++;
            }
        }
        for (int j = 1; j < n; j++) {
            int i = 0;
            int k = j;
            vector<int> v;
            while (i < m && k < n) {
                v.push_back(mat[i][k]);
                i++;
                k++;
            }
            sort(v.begin(), v.end());
            i = 0;
            k = j;
            int idx = 0;
            while (i < m && k < n) {
                mat[i][k] = v[idx];
                i++;
                k++;
                idx++;
            }
        }
        return mat;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{3,3,1,1}, {2,2,1,2}, {1,1,1,2}};
    vector<vector<int>> ans = sol.diagonalSort(mat);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
