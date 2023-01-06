// Link: https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> &colsum)
    {
        int n = colsum.size();
        vector<vector<int>> res(2, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            if (colsum[i] == 2)
            {
                res[0][i] = 1;
                res[1][i] = 1;
                upper--;
                lower--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (colsum[i] == 1)
            {
                if (upper > 0)
                {
                    res[0][i] = 1;
                    upper--;
                }
                else
                {
                    res[1][i] = 1;
                    lower--;
                }
            }
        }
        if (upper == 0 && lower == 0)
            return res;
        return {};
    }
};

int main()
{
    Solution s;
    int upper = 2, lower = 1;
    vector<int> colsum = {1, 1, 1};
    vector<vector<int>> res = s.reconstructMatrix(upper, lower, colsum);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}

