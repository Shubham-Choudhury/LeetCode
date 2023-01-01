// Link: https://leetcode.com/problems/groups-of-special-equivalent-strings/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSpecialEquivGroups(vector<string> &A)
    {
        set<pair<string, string>> s;
        for (string &a : A)
        {
            string odd = "", even = "";
            for (int i = 0; i < a.size(); i++)
            {
                if (i % 2 == 0)
                {
                    even += a[i];
                }
                else
                {
                    odd += a[i];
                }
            }
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            s.insert({odd, even});
        }
        return s.size();
    }
};

int main()
{
    Solution s;
    vector<string> A = {"a", "b", "c", "a", "c", "c"};
    cout << s.numSpecialEquivGroups(A) << endl;
    return 0;
}
