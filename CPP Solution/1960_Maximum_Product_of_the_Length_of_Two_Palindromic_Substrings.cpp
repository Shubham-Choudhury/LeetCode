// Link: https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxProduct(string s)
    {
        vector<int> d1(s.size());
        int n = s.size();
        for (int i = 0, l = 0, r = -1; i < n; ++i)
        {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
                k++;
            d1[i] = k--;
            if (i + k > r)
            {
                l = i - k;
                r = i + k;
            }
            cout << d1[i] << ' ';
        }
        vector<int> l(s.size(), 1), r(s.size(), 1);
        queue<int> q;
        for (int i = 0; i < s.size(); i++)
        {
            if (i > 0)
                l[i] = max(l[i], l[i - 1]);

            q.push(i);

            while (q.front() + d1[q.front()] - 1 < i)
            {
                q.pop();
            }

            l[i] = max(l[i], ((i - q.front()) * 2) + 1);
        }
        while (!q.empty())
            q.pop();

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (i < s.size() - 1)
                r[i] = max(r[i], r[i + 1]);

            q.push(i);

            while (q.front() - d1[q.front()] + 1 > i)
            {
                q.pop();
            }

            r[i] = max(r[i], ((q.front() - i) * 2) + 1);
        }

        long long res = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            res = max(res, (long long)l[i] * (long long)r[i + 1]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "leetcodecom";
    cout << sol.maxProduct(s) << endl;
    return 0;
}