// Link: https://leetcode.com/problems/longest-mountain-in-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestMountain(vector<int> &A)
    {
        int ans = 0;
        int i = 0;
        while (i < A.size())
        {
            int j = i;
            if (j + 1 < A.size() && A[j] < A[j + 1])
            {
                while (j + 1 < A.size() && A[j] < A[j + 1])
                    j++;
                if (j + 1 < A.size() && A[j] > A[j + 1])
                {
                    while (j + 1 < A.size() && A[j] > A[j + 1])
                        j++;
                    ans = max(ans, j - i + 1);
                }
            }
            i = max(i + 1, j);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> A = {2, 1, 4, 7, 3, 2, 5};
    cout << sol.longestMountain(A) << endl;
    return 0;
}