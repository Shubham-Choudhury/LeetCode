// Link: https://leetcode.com/problems/prison-cells-after-n-days/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int> &res, int n)
    {
        vector<int> tmp(8);
        vector<vector<int>> seen;
        while (n--)
        {
            for (int i = 1; i < 7; i++)
            {
                tmp[i] = res[i - 1] == res[i + 1];
            }
            if (seen.size() && seen.front() == tmp)
                return seen[n % seen.size()];
            else
                seen.push_back(tmp);
            res = tmp;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> cells = {0, 1, 0, 1, 1, 0, 0, 1};
    int N = 7;
    vector<int> res = sol.prisonAfterNDays(cells, N);
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
