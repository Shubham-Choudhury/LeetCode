// Link: https://leetcode.com/problems/array-of-doubled-pairs/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canReorderDoubled(vector<int> &A)
    {
        map<int, int> m;
        for (int a : A)
        {
            m[a]++;
        }
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second > 0)
            {
                if (it->first < 0)
                {
                    if (it->first % 2 != 0 || m.find(it->first / 2) == m.end() || m[it->first / 2] < it->second)
                    {
                        return false;
                    }
                    m[it->first / 2] -= it->second;
                }
                else
                {
                    if (m.find(it->first * 2) == m.end() || m[it->first * 2] < it->second)
                    {
                        return false;
                    }
                    m[it->first * 2] -= it->second;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> A = {4, -2, 2, -4};
    cout << sol.canReorderDoubled(A) << endl;
    return 0;
}
