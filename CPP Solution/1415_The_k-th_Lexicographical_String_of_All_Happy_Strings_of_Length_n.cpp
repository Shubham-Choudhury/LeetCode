// Link: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string getHappyString(int n, int k)
    {
        string res = "";
        vector<string> v;
        string s = "abc";
        helper(v, s, n, res);
        if (k > v.size())
            return "";
        return v[k - 1];
    }

    void helper(vector<string> &v, string s, int n, string res)
    {
        if (n == 0)
        {
            v.push_back(res);
            return;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (res.size() == 0 || res[res.size() - 1] != s[i])
            {
                res.push_back(s[i]);
                helper(v, s, n - 1, res);
                res.pop_back();
            }
        }
    }
};

int main(){
    Solution s;
    int n = 3;
    int k = 9;

    string ans = s.getHappyString(n, k);
    cout << ans << endl;
    return 0;
}