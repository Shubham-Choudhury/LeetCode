// Link: https://leetcode.com/problems/restore-ip-addresses/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        string ip;
        dfs(s, 0, 0, ip, res);
        return res;
    }
    void dfs(string s, int start, int step, string ip, vector<string> &res)
    {
        if (start == s.size() && step == 4)
        {
            ip.erase(ip.end() - 1);
            res.push_back(ip);
            return;
        }
        if (s.size() - start > (4 - step) * 3)
            return;
        if (s.size() - start < (4 - step))
            return;
        int num = 0;
        for (int i = start; i < start + 3; ++i)
        {
            num = num * 10 + (s[i] - '0');
            if (num <= 255)
            {
                ip += s[i];
                dfs(s, i + 1, step + 1, ip + '.', res);
            }
            if (num == 0)
                break;
        }
    }
};

int main()
{
    Solution s;
    vector<string> res = s.restoreIpAddresses("25525511135");
    for (auto i : res)
        cout << i << endl;
    return 0;
}