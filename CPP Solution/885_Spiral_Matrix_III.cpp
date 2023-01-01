// Link: https://leetcode.com/problems/spiral-matrix-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r, int c)
    {
        vector<vector<int>> res = {{r, c}};
        int dx = 0, dy = 1, tmp;
        for (int n = 0; res.size() < R * C; n++)
        {
            for (int i = 0; i < n / 2 + 1; i++)
            {
                r += dx, c += dy;
                if (0 <= r && r < R && 0 <= c && c < C)
                    res.push_back({r, c});
            }
            tmp = dx, dx = dy, dy = -tmp;
        }
        return res;
    }
};

int main()
{
    Solution s;
    int R = 1, C = 4, r0 = 0, c0 = 0;
    vector<vector<int>> ans = s.spiralMatrixIII(R, C, r0, c0);
    for (auto v : ans)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
