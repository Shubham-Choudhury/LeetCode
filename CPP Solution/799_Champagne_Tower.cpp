// Link: https://leetcode.com/problems/champagne-tower/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        double arr[100][100] = {0};
        arr[0][0] = poured;

        for (size_t i = 0; i < query_row; i++)
        {
            for (size_t j = 0; j <= i; j++)
            {
                arr[i + 1][j] += 0 < (arr[i][j] - 1.0) / 2.0 ? (arr[i][j] - 1.0) / 2.0 : 0;
                arr[i + 1][j + 1] += 0 < (arr[i][j] - 1.0) / 2.0 ? (arr[i][j] - 1.0) / 2.0 : 0;
            }
        }

        return arr[query_row][query_glass] < 1 ? arr[query_row][query_glass] : 1;
    }
};

int main()
{
    Solution sol;
    cout << sol.champagneTower(1, 1, 1) << endl;
    cout << sol.champagneTower(2, 1, 1) << endl;
    cout << sol.champagneTower(100000009, 33, 17) << endl;
    return 0;
}
