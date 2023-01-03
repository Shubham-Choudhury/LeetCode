// Link: https://leetcode.com/problems/reorder-data-in-log-files/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        vector<string> ans;
        vector<string> digitLogs;
        vector<pair<string, string>> letterLogs;
        for (string log : logs)
        {
            int i = 0;
            while (log[i] != ' ')
                i++;
            if (isdigit(log[i + 1]))
            {
                digitLogs.push_back(log);
            }
            else
            {
                letterLogs.push_back({log.substr(i + 1), log.substr(0, i)});
            }
        }
        sort(letterLogs.begin(), letterLogs.end());
        for (pair<string, string> log : letterLogs)
        {
            ans.push_back(log.second + " " + log.first);
        }
        for (string log : digitLogs)
        {
            ans.push_back(log);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> logs = {"dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"};
    vector<string> ans = sol.reorderLogFiles(logs);
    for (string s : ans)
    {
        cout << s << endl;
    }
    return 0;
}