// Link: https://leetcode.com/problems/find-a-peak-element-ii/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int maxCol = 0;
            for (int j = 1; j < m; j++) {
                if (mat[mid][j] > mat[mid][maxCol])
                    maxCol = j;
            }
            if (mid > 0 && mat[mid][maxCol] < mat[mid - 1][maxCol])
                high = mid - 1;
            else if (mid < n - 1 && mat[mid][maxCol] < mat[mid + 1][maxCol])
                low = mid + 1;
            else
                return {mid, maxCol};
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = {{1, 4}, {3, 2}};
    vector<int> ans = s.findPeakGrid(mat);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}