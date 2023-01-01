// Link: https://leetcode.com/problems/number-of-visible-people-in-a-queue/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        vector<int> stk, ans;
        for (int i = heights.size() - 1; i >= 0; i--)
        {
            int cnt = 0;
            while (stk.size() && stk.back() <= heights[i])
            {
                ++cnt;
                stk.pop_back();
            }
            ans.push_back(cnt + (stk.size() > 0)); // stk.size() > 0 means the current person can see the first right person who is higher than him.
            stk.push_back(heights[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> heights = {10, 6, 8, 5, 11, 9};
    vector<int> ans = s.canSeePersonsCount(heights);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    return 0;
}