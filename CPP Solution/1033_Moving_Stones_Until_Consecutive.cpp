// Link: https://leetcode.com/problems/moving-stones-until-consecutive/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> numMovesStones(int a, int b, int c)
    {
        vector<int> s = {a, b, c};
        sort(begin(s), end(s));
        if (s[2] - s[0] == 2)
            return {0, 0};
        return {min(s[1] - s[0], s[2] - s[1]) <= 2 ? 1 : 2, s[2] - s[0] - 2};
    }
};

int main()
{
    Solution sol;
    int a = 1, b = 2, c = 5;
    vector<int> res = sol.numMovesStones(a, b, c);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
