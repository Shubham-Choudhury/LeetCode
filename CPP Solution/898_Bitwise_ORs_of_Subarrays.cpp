// Link: https://leetcode.com/problems/bitwise-ors-of-subarrays/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarrayBitwiseORs(vector<int> &A)
    {
        set<int> s;
        set<int> ans;
        for (int i = 0; i < A.size(); i++)
        {
            set<int> temp;
            temp.insert(A[i]);
            for (auto x : s)
            {
                temp.insert(x | A[i]);
            }
            s = temp;
            for (auto x : s)
            {
                ans.insert(x);
            }
        }
        return ans.size();
    }
};

int main()
{
    Solution s;
    vector<int> A = {1, 1, 2};
    cout << s.subarrayBitwiseORs(A) << endl;
    return 0;
}
