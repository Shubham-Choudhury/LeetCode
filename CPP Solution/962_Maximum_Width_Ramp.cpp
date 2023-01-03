// Link: https://leetcode.com/problems/maximum-width-ramp/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxWidthRamp(vector<int> &A)
    {
        stack<int> s;
        int res = 0, n = A.size();
        for (int i = 0; i < n; ++i)
            if (s.empty() || A[s.top()] > A[i])
                s.push(i);
        for (int i = n - 1; i > res; --i)
            while (!s.empty() && A[s.top()] <= A[i])
                res = max(res, i - s.top()), s.pop();
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> A = {6, 0, 8, 2, 1, 5};
    cout << sol.maxWidthRamp(A) << endl;
    return 0;
}
