// Link: https://leetcode.com/problems/expression-add-operators/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
    typedef long long int i64;

    string myS;
    const char *s;
    i64 target;
    int slen;

public:
    vector<string> addOperators(const string &num, int t)
    {
        myS = num;
        slen = myS.size();
        s = myS.c_str();
        target = t;

        vector<string> res;
        char buf[slen * 2 + 1];

        int lmax = (s[0] == '0' ? 1 : slen);
        i64 v = 0;
        for (int l = 1; l <= lmax; ++l)
        {
            int c = s[l - 1];
            v = v * 10 + (c - '0');
            buf[l - 1] = c;
            processTail(0, v, l, buf, l, res);
        }
        return res;
    }

    void processTail(i64 prevsum, i64 last, int pos, char *buf, int bufpos, vector<string> &res)
    {
        if (pos == slen)
        {
            if (prevsum + last == target)
            {
                buf[bufpos] = 0;
                res.push_back(buf);
            }
            return;
        }

        int lmax = (s[pos] == '0' ? 1 : slen - pos);
        i64 v = 0;
        for (int l = 1; l <= lmax; ++l)
        {
            int c = s[pos + l - 1];
            v = v * 10 + (c - '0');

            buf[bufpos] = '+';
            buf[bufpos + l] = c;
            processTail(prevsum + last, v, pos + l, buf, bufpos + l + 1, res);

            buf[bufpos] = '-';
            processTail(prevsum + last, -v, pos + l, buf, bufpos + l + 1, res);

            buf[bufpos] = '*';
            processTail(prevsum, last * v, pos + l, buf, bufpos + l + 1, res);
        }
    }
};

int main()
{
    string num = "123";
    int target = 6;
    Solution sol;
    vector<string> res = sol.addOperators(num, target);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}
