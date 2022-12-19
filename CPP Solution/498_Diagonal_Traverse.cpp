// Link: https://leetcode.com/problems/diagonal-traverse/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty()) return result;
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = 0;
        int d = 1;
        for(int i = 0; i < m * n; i++) {
            result.push_back(matrix[row][col]);
            row -= d;
            col += d;
            if(row >= m) {
                row = m - 1;
                col += 2;
                d = -d;
            }
            if(col >= n) {
                col = n - 1;
                row += 2;
                d = -d;
            }
            if(row < 0) {
                row = 0;
                d = -d;
            }
            if(col < 0) {
                col = 0;
                d = -d;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> res = s.findDiagonalOrder(matrix);
    for(auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
