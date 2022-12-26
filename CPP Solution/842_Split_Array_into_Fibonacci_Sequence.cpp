// Link: https://leetcode.com/problems/split-array-into-fibonacci-sequence/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution
{
public:
    vector<int> ans;
    bool check(string S, int index, ll num1, ll num2, bool tag)
    {
        if (index >= S.size() && tag)
            return true;
        ll sum = 0;
        for (int i = index; i < S.size() && sum * 10 < (INT_MAX - S[i] - '0'); i++)
        {
            if (i > index && sum == 0)
                return false;
            sum = sum * 10 + (ll)(S[i] - '0');
            if (num2 == -1)
            {
                if (check(S, i + 1, sum, num1, tag))
                {
                    ans.push_back((int)sum);
                    return true;
                }
            }
            else
            {
                if (sum == num1 + num2 && check(S, i + 1, sum, num1, true))
                {
                    ans.push_back((int)sum);
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string S)
    {
        ll num = 0;
        bool tag = false;
        if (S[0] == '0')
        {
            if (check(S, 1, num, -1, tag))
            {
                ans.push_back((int)num);
            }
        }
        else
        {
            for (int i = 0; i < S.size() && num * 10 < (INT_MAX - S[i] - '0'); i++)
            {
                num = num * 10 + (S[i] - '0');
                if (check(S, i + 1, num, -1, tag))
                {
                    ans.push_back((int)num);
                    break;
                }
            }
        }
        if (ans.size() <= 2)
            return vector<int>{};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    string S = "123456579";
    vector<int> res = s.splitIntoFibonacci(S);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}
