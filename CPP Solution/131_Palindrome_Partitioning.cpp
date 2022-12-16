// Link: https://leetcode.com/problems/palindrome-partitioning/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, 0, path, res);
        return res;
    }

    void dfs(string s, int start, vector<string> &path, vector<vector<string>> &res)
    {
        if (start == s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++)
        {
            if (isPalindrome(s, start, i))
            {
                path.push_back(s.substr(start, i - start + 1));
                dfs(s, i + 1, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end)
    {
        while (start < end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution a;
    vector<vector<string>> b = a.partition("aab");
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
