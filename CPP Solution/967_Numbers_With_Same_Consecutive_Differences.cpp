// Link: https://leetcode.com/problems/numbers-with-same-consecutive-differences/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> res;
        for (int i = 1; i <= 9; ++i)
            dfs(i, n - 1, k, res);
        if (n == 1)
            res.push_back(0);
        return res;
    }

    void dfs(int num, int n, int k, vector<int> &res)
    {
        if (n == 0)
        {
            res.push_back(num);
            return;
        }
        int last = num % 10;
        if (last + k <= 9)
            dfs(num * 10 + last + k, n - 1, k, res);
        if (last - k >= 0 && k != 0)
            dfs(num * 10 + last - k, n - 1, k, res);
    }
};

int main()
{
    Solution sol;
    int n = 3, k = 7;
    vector<int> res = sol.numsSameConsecDiff(n, k);
    for (auto &i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
