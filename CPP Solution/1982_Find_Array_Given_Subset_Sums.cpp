// Link: https://leetcode.com/problems/find-array-given-subset-sums/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> ans;
    map<int, int> mp;
    vector<int> recoverArray(int n, vector<int> &sums)
    {
        sort(sums.begin(), sums.end());
        solve(sums);
        return ans;
    }

    void solve(vector<int> &sums)
    {
        // base case
        if (sums.size() == 2)
        {
            ans.push_back(sums[0] + sums[1]);
            return;
        }
        bool des = false;
        vector<int> v1;
        vector<int> v2;
        int d = sums[1] - sums[0];
        for (int i = 0; i < sums.size(); i++)
        {
            if (!mp[sums[i]])
            {
                v1.push_back(sums[i]);
                mp[sums[i] + d]++;
                if (sums[i] == 0)
                    des = true;
            }
            else
            {
                v2.push_back(sums[i]);
                mp[sums[i]]--;
            }
        }
        if (des)
        {
            ans.push_back(d);
            solve(v1);
        }
        else
        {
            ans.push_back(-d);
            solve(v2);
        }
    }
};

int main()
{
    Solution s;
    vector<int> sums = {1, 2, 3, 4};
    vector<int> ans = s.recoverArray(4, sums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
