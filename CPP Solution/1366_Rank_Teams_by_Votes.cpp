// Link: https://leetcode.com/problems/rank-teams-by-votes/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string rankTeams(vector<string> &votes)
    {
        vector<vector<int>> count(26, vector<int>(27));
        for (char &c : votes[0])
            count[c - 'A'][26] = c;

        for (string &vote : votes)
            for (int i = 0; i < vote.length(); ++i)
                --count[vote[i] - 'A'][i];
        sort(count.begin(), count.end());
        string res;
        for (int i = 0; i < votes[0].length(); ++i)
            res += count[i][26];
        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> votes = {"ABC", "ACB", "ABC", "ACB", "ACB"};
    cout << sol.rankTeams(votes) << endl;
    return 0;
}
