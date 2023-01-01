// Link: https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getXORSum(vector<int> &A, vector<int> &B)
    {
        int a = 0, b = 0;
        for (auto x : A)
            a ^= x;
        for (auto x : B)
            b = b ^ (x & a);
        return b;
    }
};

int main()
{
    Solution sol;
    vector<int> arr1, arr2;
    int ans;

    // Output: 8
    arr1 = {1, 2, 3}, arr2 = {6, 5};

    // Output: 0
    // arr1 = {12}, arr2 = {4};

    ans = sol.getXORSum(arr1, arr2);
    cout << ans << endl;

    return 0;
}
