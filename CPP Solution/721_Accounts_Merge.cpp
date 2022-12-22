// Link: https://leetcode.com/problems/accounts-merge/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        unordered_map<string, string> emailToName;
        unordered_map<string, vector<string>> graph;
        for (auto account : accounts)
        {
            string name = account[0];
            for (int i = 1; i < account.size(); i++)
            {
                emailToName[account[i]] = name;
                graph[account[1]].push_back(account[i]);
                graph[account[i]].push_back(account[1]);
            }
        }
        unordered_set<string> visited;
        for (auto email : emailToName)
        {
            if (visited.count(email.first))
                continue;
            visited.insert(email.first);
            vector<string> emails;
            stack<string> s;
            s.push(email.first);
            while (!s.empty())
            {
                string cur = s.top();
                s.pop();
                emails.push_back(cur);
                for (string next : graph[cur])
                {
                    if (visited.count(next))
                        continue;
                    visited.insert(next);
                    s.push(next);
                }
            }
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), emailToName[email.first]);
            res.push_back(emails);
        }
        return res;
    }
};

int main()
{
    Solution obj;
    vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};
    vector<vector<string>> res = obj.accountsMerge(accounts);
    for (auto account : res)
    {
        for (string email : account)
            cout << email << " ";
        cout << endl;
    }

    return 0;
}