// Link: https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxDepthAfterSplit(string seq)
    {
        vector<int> ans;
        int depth = 0;
        for (int i = 0; i < seq.size(); i++)
        {
            if (seq[i] == '(')
            {
                depth++;
                ans.push_back(depth % 2);
            }
            else
            {
                ans.push_back(depth % 2);
                depth--;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string seq = "(()())";
    vector<int> ans = sol.maxDepthAfterSplit(seq);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
