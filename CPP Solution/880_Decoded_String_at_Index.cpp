// Link: https://leetcode.com/problems/decoded-string-at-index/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeAtIndex(string S, int K)
    {
        long long n = 0;
        int i = 0;
        for (; i < S.size(); i++)
        {
            if (isdigit(S[i]))
            {
                n *= S[i] - '0';
            }
            else
            {
                n++;
            }
            if (n >= K)
            {
                break;
            }
        }
        for (; i >= 0; i--)
        {
            if (isdigit(S[i]))
            {
                n /= S[i] - '0';
                K %= n;
            }
            else
            {
                if (K % n == 0)
                {
                    return string(1, S[i]);
                }
                n--;
            }
        }
        return "";
    }
};

int main()
{
    Solution s;
    cout << s.decodeAtIndex("leet2code3", 10) << endl;
    cout << s.decodeAtIndex("ha22", 5) << endl;
    cout << s.decodeAtIndex("a2345678999999999999999", 1) << endl;
    return 0;
}
