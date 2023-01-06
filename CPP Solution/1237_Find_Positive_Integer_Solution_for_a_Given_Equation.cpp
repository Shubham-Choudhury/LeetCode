// Link: https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findSolution(CustomFunction &customfunction, int z)
    {
        vector<vector<int>> res;
        int i = 1, j = 1000;
        while (i <= 1000 && j >= 1)
        {
            int val = customfunction.f(i, j);
            if (val == z)
            {
                res.push_back({i, j});
                i++;
                j--;
            }
            else if (val < z)
                i++;
            else
                j--;
        }
        return res;
    }
};

class CustomFunction
{
public:
    // Returns f(x, y) for any given positive integers x and y.
    // Note that f(x, y) is increasing with respect to both x and y.
    // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
    int f(int x, int y);
};

int main()
{
    Solution s;
    return 0;
}