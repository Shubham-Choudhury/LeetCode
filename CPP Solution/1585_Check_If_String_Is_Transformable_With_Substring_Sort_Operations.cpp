// Link: https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isTransformable(string s, string t)
    {
        vector<vector<int>> idx(10);
        vector<int> pos(10);
        for (int i = 0; i < s.size(); ++i)
            idx[s[i] - '0'].push_back(i);
        for (auto ch : t)
        {
            int d = ch - '0';
            if (pos[d] >= idx[d].size())
                return false;
            for (auto i = 0; i < d; ++i)
                if (pos[i] < idx[i].size() && idx[i][pos[i]] < idx[d][pos[d]])
                    return false;
            ++pos[d];
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isTransformable("84532", "34852") << endl;
    cout << s.isTransformable("34521", "23415") << endl;
    cout << s.isTransformable("12345", "12435") << endl;
    cout << s.isTransformable("1", "2") << endl;
    return 0;
}