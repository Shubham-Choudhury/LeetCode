// Link: https://leetcode.com/problems/circular-permutation-in-binary-representation/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> circularPermutation(int n, int start)
    {
        vector<int> res;
        for (int i = 0; i < (1 << n); i++)
            res.push_back(start ^ i ^ (i >> 1));
        return res;
    }
};

int main()
{
    Solution s;
    int n = 2;
    int start = 3;
    vector<int> res = s.circularPermutation(n, start);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}
