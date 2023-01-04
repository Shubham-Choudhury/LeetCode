// Link: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDominoRotations(vector<int> &A, vector<int> &B)
    {
        int ans = INT_MAX;
        int n = A.size();
        for (int i = 1; i <= 6; i++)
        {
            int countA = 0;
            int countB = 0;
            for (int j = 0; j < n; j++)
            {
                if (A[j] != i && B[j] != i)
                    break;
                if (A[j] != i)
                    countA++;
                if (B[j] != i)
                    countB++;
                if (j == n - 1)
                    ans = min(ans, min(countA, countB));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    Solution sol;
    vector<int> A = {2, 1, 2, 4, 2, 2};
    vector<int> B = {5, 2, 6, 2, 3, 2};
    cout << sol.minDominoRotations(A, B) << endl;
    return 0;
}
