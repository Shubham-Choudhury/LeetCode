// Link: https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int n, m;

    // flipping the neighbours
    vector<vector<int>> flip(vector<vector<int>> &mat, int x, int x1)
    {
        mat[x][x1] ^= 1;
        int left[4] = {-1, 0, 1, 0};
        int right[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int row = x + left[i];
            int col = x1 + right[i];

            if (row >= 0 && row < n && col >= 0 && col < m)
            {
                mat[row][col] ^= 1;
            }
        }
        return mat;
    }

    // checking for all zeros
    bool isallzero(vector<vector<int>> mat)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] != 0)
                    return false;
            }
        }
        return 1;
    }

    // recursive function
    int justwow(vector<vector<int>> mat, int i, int j)
    {

        // base condition
        if (j == m)
        {
            i++;
            j = 0;
        }
        if (i == n)
            if (isallzero(mat))
                return 0;
            else
                return 999999;

        auto first = justwow(mat, i, j + 1);                  // decide not to take index
        auto second = justwow(flip(mat, i, j), i, j + 1) + 1; // decide to take and flip it's neighbours + 1

        return min(first, second); // return minimum of both
    }
    int minFlips(vector<vector<int>> &mat)
    {
        n = mat.size();
        m = mat[0].size();

        int ans = justwow(mat, 0, 0);

        if (ans < 999999)
            return ans;
        else
            return -1;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> mat = {{1, 1, 1}, {1, 0, 1}, {0, 0, 0}};
    cout << s.minFlips(mat) << endl;
    return 0;
}
