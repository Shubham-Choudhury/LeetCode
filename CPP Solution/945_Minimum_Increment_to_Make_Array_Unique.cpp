// Link: https://leetcode.com/problems/minimum-increment-to-make-array-unique/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minIncrementForUnique(vector<int> &A)
    {
        int ans = 0;
        sort(A.begin(), A.end());
        for (int i = 1; i < A.size(); i++)
        {
            if (A[i] <= A[i - 1])
            {
                ans += A[i - 1] - A[i] + 1;
                A[i] = A[i - 1] + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> A = {3, 2, 1, 2, 1, 7};
    cout << sol.minIncrementForUnique(A) << endl;
    return 0;
}
