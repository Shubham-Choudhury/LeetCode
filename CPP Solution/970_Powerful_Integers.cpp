// Link: https://leetcode.com/problems/powerful-integers/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        unordered_set<int> res;
        for (int i = 1; i < bound; i *= x)
        {
            for (int j = 1; i + j <= bound; j *= y)
            {
                res.insert(i + j);
                if (y == 1)
                    break;
            }
            if (x == 1)
                break;
        }
        return vector<int>(res.begin(), res.end());
    }
};

int main()
{
    Solution sol;
    int x = 2, y = 3, bound = 10;
    vector<int> res = sol.powerfulIntegers(x, y, bound);
    for (auto &i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
