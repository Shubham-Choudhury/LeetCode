// Link: https://leetcode.com/problems/find-and-replace-in-string/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findReplaceString(string S, vector<int> &indexes, vector<string> &sources, vector<string> &targets)
    {
        vector<pair<int, int>> v;
        for (size_t i = 0; i < indexes.size(); i++)
        {
            v.push_back({indexes[i], i});
        }
        sort(v.begin(), v.end());
        for (int i = v.size() - 1; i >= 0; i--)
        {
            int index = v[i].first;
            int j = v[i].second;
            if (S.substr(index, sources[j].size()) == sources[j])
            {
                S = S.substr(0, index) + targets[j] + S.substr(index + sources[j].size());
            }
        }
        return S;
    }
};

int main()
{
    Solution sol;
    vector<int> indexes = {0, 2};
    vector<string> sources = {"a", "cd"};
    vector<string> targets = {"eee", "ffff"};
    cout << sol.findReplaceString("abcd", indexes, sources, targets) << endl;
    return 0;
}