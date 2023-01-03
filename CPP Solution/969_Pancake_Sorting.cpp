// Link: https://leetcode.com/problems/pancake-sorting/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pancakeSort(vector<int> &A)
    {
        vector<int> res;
        int n = A.size();
        for (int i = n; i > 0; --i)
        {
            int j = 0;
            while (A[j] != i)
                ++j;
            reverse(A.begin(), A.begin() + j + 1);
            res.push_back(j + 1);
            reverse(A.begin(), A.begin() + i);
            res.push_back(i);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> A = {3, 2, 4, 1};
    vector<int> res = sol.pancakeSort(A);
    for (auto &i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}

