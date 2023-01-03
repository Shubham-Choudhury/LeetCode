// Link: https://leetcode.com/problems/largest-time-for-given-digits/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestTimeFromDigits(vector<int> &A)
    {
        sort(A.begin(), A.end());
        string ans = "";
        do
        {
            if ((A[0] == 2 && A[1] < 4 || A[0] < 2) && A[2] < 6)
            {
                ans = max(ans, to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]));
            }
        } while (next_permutation(A.begin(), A.end()));
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> A = {1, 2, 3, 4};
    cout << sol.largestTimeFromDigits(A) << endl;
    return 0;
}
