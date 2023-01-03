// Link: https://leetcode.com/problems/binary-subarrays-with-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &A, int S)
    {
        unordered_map<int, int> c({{0, 1}});
        int psum = 0, res = 0;
        for (int i : A)
        {
            psum += i;
            res += c[psum - S];
            c[psum]++;
        }
        return res;
    }
};

int main()
{
    Solution S;
    vector<int> A = {1, 0, 1, 0, 1};
    int S = 2;
    cout << S.numSubarraysWithSum(A, S) << endl;
    return 0;
}
