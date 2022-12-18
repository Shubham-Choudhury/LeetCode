// Link: https://leetcode.com/problems/smallest-sufficient-team/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
    int INF = 1e9 + 7;
    unordered_map<string, int> mp;
    int dp[61][1 << 16];

    int kil(int idx, int mask, vector<vector<string>> &people)
    {
        if (idx == people.size())
        {
            if (mask)
                return dp[idx][mask] = INF;
            return dp[idx][mask] = 0;
        }

        if (dp[idx][mask] != -1)
            return dp[idx][mask];
        dp[idx][mask] = INF;

        dp[idx][mask] = min(dp[idx][mask], kil(idx + 1, mask, people));
        int nmask = mask;
        for (int i = 0; i < people[idx].size(); i++)
        {
            int pos = mp[people[idx][i]];
            if (nmask & (1 << pos))
                nmask ^= (1 << pos);
        }
        dp[idx][mask] = min(dp[idx][mask], kil(idx + 1, nmask, people) + 1);

        return dp[idx][mask];
    }

    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
    {
        memset(dp, -1, sizeof dp);
        int x = 0;
        for (string s : req_skills)
            mp[s] = x++;

        kil(0, (1 << x) - 1, people);
        vector<int> res;

        int idx = 0;
        int mask = (1 << x) - 1;

        while (idx != people.size())
        {
            if (dp[idx][mask] == dp[idx + 1][mask])
            {
                idx += 1;
                continue;
            }
            int nmask = mask;
            for (int i = 0; i < people[idx].size(); i++)
            {
                int pos = mp[people[idx][i]];
                if (nmask & (1 << pos))
                    nmask ^= (1 << pos);
            }
            if (dp[idx][mask] == dp[idx + 1][nmask] + 1)
            {
                res.push_back(idx);
                idx += 1;
                mask = nmask;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> req_skills = {"java", "nodejs", "reactjs"};
    vector<vector<string>> people = {{"java"}, {"nodejs"}, {"nodejs", "reactjs"}};
    vector<int> res = s.smallestSufficientTeam(req_skills, people);
    for (auto &i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
