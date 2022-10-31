// Link: https://leetcode.com/problems/toeplitz-matrix/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(i > 0 && j > 0 && matrix[i][j] != matrix[i-1][j-1])
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    Solution s;
    cout << s.isToeplitzMatrix(matrix);
    return 0;
}