// Link: https://leetcode.com/problems/shifting-letters/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shiftingLetters(string S, vector<int> &shifts)
    {
        int sum = 0;
        for (int i = shifts.size() - 1; i >= 0; i--)
        {
            sum = (sum + shifts[i]) % 26;
            S[i] = (S[i] - 'a' + sum) % 26 + 'a';
        }
        return S;
    }
};

int main()
{
    Solution sol;
    string S = "abc";
    vector<int> shifts = {3, 5, 9};
    cout << sol.shiftingLetters(S, shifts) << endl;
    return 0;
}