// Link: https://leetcode.com/problems/previous-permutation-with-one-swap/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> prevPermOpt1(vector<int> &A)
    {
        int n = A.size();
        int i = n - 2;
        while (i >= 0 && A[i] <= A[i + 1])
            i--;
        if (i < 0)
            return A;
        int j = n - 1;
        while (j > i && A[j] >= A[i])
            j--;
        while (j > i && A[j] == A[j - 1])
            j--;
        swap(A[i], A[j]);
        return A;
    }
};

int main()
{
    Solution sol;
    vector<int> A = {3, 1, 1, 3};
    vector<int> res = sol.prevPermOpt1(A);
    for (auto &x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}
