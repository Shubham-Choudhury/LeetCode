// Link: https://leetcode.com/problems/count-square-submatrices-with-all-ones/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] && i && j)
                    matrix[i][j] += min({matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]});
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans += matrix[i][j];
        return ans;
    }
};

int main()
{
    vector<vector<int>> matrix = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
    Solution *obj = new Solution();
    cout << obj->countSquares(matrix) << endl;
    return 0;
}
