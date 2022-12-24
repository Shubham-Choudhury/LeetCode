// Link: https://leetcode.com/problems/pyramid-transition-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        unordered_map<string, vector<char>> m;
        for (auto &s : allowed)
            m[s.substr(0, 2)].push_back(s.back());
        unordered_set<string> failedStates;
        return helper(bottom, m, 0, "", failedStates);
    }
    bool helper(string bottom, unordered_map<string, vector<char>> &m, int start, string next, unordered_set<string> &failedStates)
    {
        if (bottom.size() == 1)
            return true;
        if (start == (int)bottom.size() - 1)
            return helper(next, m, 0, "", failedStates);
        if (failedStates.find(bottom.substr(start) + "#" + next) != failedStates.end())
        {
            return false;
        }
        for (char c : m[bottom.substr(start, 2)])
            if (helper(bottom, m, start + 1, next + c, failedStates))
                return true;
        failedStates.insert(bottom.substr(start) + "#" + next);
        return false;
    }
};

int main()
{
    Solution s;
    string bottom;
    vector<string> allowed;
    bool ans;

    // Output: true
    bottom = "BCD";
    allowed = {"BCG", "CDE", "GEA", "FFF"};
    ans = s.pyramidTransition(bottom, allowed);
    cout << ans << endl;

    // Output: false
    bottom = "AABA";
    allowed = {"AAA", "AAB", "ABA", "ABB", "BAC"};
    ans = s.pyramidTransition(bottom, allowed);
    cout << ans << endl;

    return 0;
}
