// Link: https://leetcode.com/problems/delete-columns-to-make-sorted/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string> &A)
    {
        int n = A.size();
        int m = A[0].size();
        int ans = 0;
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (A[i][j] > A[i + 1][j])
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> A = {"cba", "daf", "ghi"};
    cout << sol.minDeletionSize(A) << endl;
    return 0;
}
